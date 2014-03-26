#ifndef WEBPAGE_H_
#define WEBPAGE_H_
#include <vector>
#include <string>
#include <map>
#include "lib/stlset.h"

class WebPage {
  public:
    WebPage ();    // constructor that creates an empty page
    WebPage (string filename);
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