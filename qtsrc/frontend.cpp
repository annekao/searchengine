#include <QApplication>
#include <iostream>
#include <fstream>
#include "../webpage.h"
#include "mainwin.h"

int main(int argc, char *argv[])
{
	try{
	char* infile;
  		infile = argv[1];
		if (argc != 2){
			cout << "Wrong number of inputs. Exiting" << endl;
			return 0;
		}
	  	ifstream fin;
	  	fin.open(infile);
	  	if(!fin){
    		cout << "Error. Invalid File. Exiting." << endl;
    		return -1;
    	}
    	else{
    		string temp;
            map< string,Set<WebPage*> > wpm;
            map<string, WebPage*> allLinks;

            //create empty webpages
            while(!fin.eof()){;
                fin >> temp;
                map<string,WebPage*>::iterator it = allLinks.find(temp);
                if(it!=allLinks.end()){
                    (*it->second).parse();
                }
                else{
                    WebPage *wTemp = new WebPage(temp, &allLinks);
                    wTemp->parse();
                    allLinks[temp] = wTemp;
                }
            }
         
            //creating the map for webpage
            
            for(map<string,WebPage*>::iterator i = allLinks.begin(); i!=allLinks.end(); ++i){
                Set<string> web = (i->second)->allWords();      //put keywords into a temporary set
                Set<WebPage*> sTemp;
                sTemp.insert(i->second);                        //add file to webpage set
                for (Set<string>::iterator it = web.begin(); it!=web.end(); ++it){  //iterate through key words
                    if(wpm.find(*it)!=wpm.end()){                            //mostlikely to occur, check if already associated
                        Set<WebPage*> reassociate = wpm.at(*it);  //have to "reassociate"
                        reassociate.insert(i->second);                 //obtain previous set and copy it over
                        wpm.erase(*it);                              //add the new webpage and remove the prev association
                        wpm[*it]=reassociate;                //reassociate
                    }
                    else
                        wpm[*it]=sTemp;              //if empty should default to adding file
                }
            }

            QApplication app(argc, argv);
			MainWin window(wpm, allLinks);
			window.setWindowTitle("Search Engine");
			window.setFixedSize(600,500);
			window.show();
			return app.exec();
            for (map<string,WebPage*>::iterator it = allLinks.begin(); it!=allLinks.end(); ++it){ //delete dynamically allocated memory 
                delete it->second;
            }
        }
    }
    catch(string &file){
        cout<<file;
        cout << "Invalid file name in list. Please revise your file. Exiting program." << endl;
    }

}