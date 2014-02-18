// required headers go here
#ifndef WEBPAGE_H_
#define WEBPAGE_H_
#include <fstream>
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

   // friend ostream & operator<< (ostream & os, const WebPage & page);
      /* Declares an operator we can use to print the web page. */

  private:
    // you get to decide what goes here.
};
#endif

WebPage::WebPage(){
}

WebPage::WebPage(string filename){
  fin.open(filename);
  if(!fin){
    throw logic_error("Invalid file. Exiting program.");
  }
}

WebPage::~WebPage(){
  fin.close();
}

Set<string> WebPage::allWords () const{
  cout << "inside allwords";
  //Set<string> words; 
  //string line;
  //getline(fin,line);
  //cout << line;
  //words.add(temp);
  //return words;
}

//ostream & WebPage::operator<< (ostream & os, const WebPage & page){

//}