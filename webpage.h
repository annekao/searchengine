// required headers go here
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

  private:
    string infile;
    Set<string>* sfile;
    // you get to decide what goes here.
};
#endif

WebPage::WebPage(){
}

WebPage::WebPage(string filename) :
                  infile(filename){
  fin.open(infile);
  if(!fin){
    throw logic_error("Invalid file. Exiting program.");
  }
  string temp;
  sfile = new Set<string>;
  while(getline(fin,temp))
    sfile->add(temp);
  fin.close();
}

WebPage::~WebPage(){
}

Set<string> WebPage::allWords () const{
  Set<string> words;
  string line;
  for (string* x = sfile->first(); x!= NULL; x=sfile->next()){   
      string line = *x;  
  while(!line.empty()){  
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
  for (string* x = page.sfile->first(); x!= NULL; x=page.sfile->next()){
    os << *x << endl;
  }
  return os;
}