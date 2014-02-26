// required headers go here
//since webpage.h isn't templated, can separate the two files .h and .cpp
#ifndef WEBPAGE_H_
#define WEBPAGE_H_
#include <fstream>
#include <stdio.h>
#include <ctype.h>
#include "lib/set.h"


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

  private:
    string infile;
    List<string> lfile;
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
  for(int i = 0; getline(fin,temp); i++)  //while there are lines to get
    lfile.insert(i,temp);       //add it to the list
  fin.close();
}

WebPage::~WebPage(){
}

Set<string> WebPage::allWords () const{
  Set<string> words;
  string line;
  for(int i =0; i < lfile.size(); i++){
    line = lfile.get(i);      //for each item i the list, set to line
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
      if(words.contains(temp)==false && !temp.empty())  //makes sure there is no duplicate word
        words.add(temp);
      line.erase(0,i+1);        //moves to the next word in the string
    }
}
  return words;
}

ostream & operator<< (ostream & os, const WebPage & page){
  for(int i =0; i < page.lfile.size(); i++)   //iterates through the list to os <<
    os << page.lfile.get(i) <<endl;
  return os;
}

bool WebPage::operator==(const WebPage & page){
  return(infile.compare(page.infile)==0);
}