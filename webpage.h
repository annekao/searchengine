// required headers go here
//since webpage.h isn't templated, can separate the two files .h and .cpp
#ifndef WEBPAGE_H_
#define WEBPAGE_H_
#include <fstream>
#include <stdio.h>
#include <ctype.h>
#include <vector>
#include "lib/stlset.h"


ifstream fin;
class WebPage {
  public:
    WebPage ();    // constructor that creates an empty page
    WebPage (string filename, map<string, WebPage*> *l);
      /* constructor that initializes the page from the given file.
         Should throw an exception if the file does not exist
         or has other problems. */
    ~WebPage ();   // destructor

    Set<string> allWords () const;
      /* Returns a set containing all individual words on the web page. */   

    friend ostream & operator<< (ostream & os, const WebPage & page);
      /* Declares an operator we can use to print the web page. */
    bool operator==(const WebPage & page);
    bool operator<(const WebPage& rhs) const;

    // BEGIN PROJECT P2
    Set<WebPage*> allOutgoingLinks () const;
      /* Returns "pointers" to all webpagesthat this page has links to. 
         As discussed above, this could be as a set or via an interator,
         and it could be as actual pointers, or as strings,
         or possibly other. */

    Set<WebPage*> allIncomingLinks () const;
      /* Returns "pointers" to all webpages that link to this page.
         Same consideration as previous function. */

    string filename() const;
      /* Returns the filename from which this page was read. */

    /* Based on which overall architecture you choose, you may 
       also need/wantsome or all of the following functions. */

    void parse ();
      /* actually parses the content of the filename that was passed
         to the constructor into the object */

    void addIncomingLink (WebPage* start);
      /* Adds a link from start to the current page
         in the current page's storage */

    void addOutgoingLink (WebPage* target);
      /* Adds a link from the current page to the target
         in the curent page's storage. */

  private:
    string infile;
    vector<string> lfile;
    Set<string> words;
    Set<WebPage*> incoming;
    Set<WebPage*> outgoing;
    map<string,WebPage*> *allLinks;
    // you get to decide what goes here.
};
#endif

WebPage::WebPage(){
}

WebPage::WebPage(string filename,map<string, WebPage*> *l) :
                  infile(filename), allLinks(l){
}

WebPage::~WebPage(){
}

Set<string> WebPage::allWords () const{
  return words;
}

ostream & operator<< (ostream & os, const WebPage & page){
  for(unsigned int i =0; i < page.lfile.size(); i++){   //iterates through the list to os <<
    string line = page.lfile.at(i);
    while ( line.find("](") != string::npos){ //gets rid of the filename and paren
      int pos = line.find("](") + 1;
      int end = line.find(")", pos) + 1;
      line.erase(line.begin()+pos, line.begin()+end);
    }
    while ( line.find("[") != string::npos || line.find("]") != string::npos ){ //gets rid of brackets around anchor text
      line.erase(line.begin()+line.find("["));
      line.erase(line.begin()+line.find("]"));
    }
    os << line <<endl;
  }
  return os;
}

bool WebPage::operator==(const WebPage & page){
  return(infile.compare(page.infile)==0);
}

bool WebPage::operator<(const WebPage & rhs) const{
  return this->infile < rhs.infile;
}

Set<WebPage*> WebPage::allOutgoingLinks () const {
  return outgoing;
}

Set<WebPage*> WebPage::allIncomingLinks () const {
  return incoming;
}

string WebPage::filename() const {
  return infile;
}

void WebPage::parse () {
  fin.open(infile);
  if(!fin){
    throw infile;
  }
  string temp;
  while(getline(fin,temp))  //while there are lines to get
    lfile.push_back(temp);       //add it to the list
  fin.close();
  string line;
  for(unsigned int i =0; i < lfile.size(); i++){
    line = lfile.at(i);      //for each item i the list, set to line
    while(!line.empty()){     //while each line still has characters
      string temp;
      int k=0;

      for( ;isalnum(line[k]) || line[k] == '['; k++){              //checks if alphanumeric
        if(line[k] == '['){                         //appropriately parses anchor text
          k++;  
        }
        temp.push_back(line[k]);            //pushes back character until next word
      }

      if(line[k] == ']' && line[k+1] == '('){ 
        string link;
        k+=2;
        while(line[k] != ')'){
          link.push_back(line[k]);
          k++;
        }
        //find matching strings, 
        //if found just add the mapped webpage as outgoing link
        //if not create a dummy link, add that to the map with the filename 
        //then add the dummy link to the outgoing links
        map<string,WebPage*>::iterator it = allLinks->find(link);
        if(it!=allLinks->end()){
          addOutgoingLink(it->second);
        }
        else{
          WebPage *dummy = new WebPage(link,allLinks);
          (*allLinks)[link] = dummy;
          addOutgoingLink(dummy);
        }
      }

      for(int j = 0; temp[j]; j++){      //converts to lower case
        temp[j] = tolower(temp[j]);
      }

      if(words.find(temp)==words.end() && !temp.empty())  //makes sure there is no duplicate word
        words.insert(temp);
      line.erase(0,k+1);        //moves to the next word in the string
    }
}
}

void WebPage::addIncomingLink (WebPage* start) {
  incoming.insert(start);
}

void WebPage::addOutgoingLink (WebPage* target) {
  outgoing.insert(target);
  target->addIncomingLink(this);
}