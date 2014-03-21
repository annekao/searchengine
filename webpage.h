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
    WebPage (string filename);
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
    allOutgoingLinks () const;
      /* Returns "pointers" to all webpagesthat this page has links to. 
         As discussed above, this could be as a set or via an interator,
         and it could be as actual pointers, or as strings,
         or possibly other. */

    allIncomingLinks () const;
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

    void addOutgoingLink (Webpage* target);
      /* Adds a link from the current page to the target
         in the curent page's storage. */

  private:
    string infile;
    vector<string> lfile;
    // you get to decide what goes here.
};
#endif

WebPage::WebPage(){
}

WebPage::WebPage(string filename) :
                  infile(filename){
  fin.open(infile);
  if(!fin){
    throw infile;
  }
  string temp;
  while(getline(fin,temp))  //while there are lines to get
    lfile.push_back(temp);       //add it to the list
  fin.close();
}

WebPage::~WebPage(){
}

Set<string> WebPage::allWords () const{
  Set<string> words;
  string line;
  for(unsigned int i =0; i < lfile.size(); i++){
    line = lfile.at(i);      //for each item i the list, set to line
    while(!line.empty()){     //while each line still has characters
      string temp;
        int i=0;
      while(isalnum(line[i])){              //checks if alphanumeric
        temp.push_back(line[i]);            //pushes back character until next word
        i++;
      }
      int j = 0;
      while(temp[j]){                      //converts to lower case
        temp[j] = tolower(temp[j]);
        j++;
      }
      if(words.find(temp)==words.end() && !temp.empty())  //makes sure there is no duplicate word
        words.insert(temp);
      line.erase(0,i+1);        //moves to the next word in the string
    }
}
  return words;
}

ostream & operator<< (ostream & os, const WebPage & page){
  for(unsigned int i =0; i < page.lfile.size(); i++)   //iterates through the list to os <<
    os << page.lfile.at(i) <<endl;
  return os;
}

bool WebPage::operator==(const WebPage & page){
  return(infile.compare(page.infile)==0);
}

bool WebPage::operator<(const WebPage & rhs) const{
  return this->infile < rhs.infile;
}

allOutgoingLinks () const {
  
}
allIncomingLinks () const {
  
}
string filename() const {
  
}
void parse () {
  
}
void addIncomingLink (WebPage* start) {
  
}
void addOutgoingLink (Webpage* target) {
  
}