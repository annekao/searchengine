

#include <iostream>
#include <stdexcept>
#include <sstream>
#include <string>
#include "../webpage.h"

void trim(string&);
void print(Set<WebPage>);

int main(int argc, char *argv[]){
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
    		Map<string,Set<WebPage>> wpm;
    		
    		while(!fin.eof()){
    			fin >> temp;							//iterate through each file
    			WebPage wTemp(temp);					
    			Set<string> web = wTemp.allWords();		//put keywords into a temporary set
    			Set<WebPage> sTemp;
    			sTemp.add(wTemp);						//add file to webpage set
    			for (string* x = web.first(); x!= NULL; x=web.next()){	//iterate through key words
    				if(wpm.find(*x)!=-1){							//mostlikely to occur, check if already associated
    					Set<WebPage> reassociate = wpm.get(*x);	//have to "reassociate"
    					reassociate.add(wTemp);					//obtain previous set and copy it over
    					wpm.remove(*x);								//add the new webpage and remove the prev association
    					wpm.add(*x,reassociate);					//reassociate
    				}
    				else
						wpm.add(*x,sTemp);				//if empty should default to adding file
				}
    		}
    		string input;
    		while (input != "."){
    			cout << "Enter <.> to exit the program." << endl << "Please enter your query: ";
    			getline(cin,input);
    			int j = 0;
    			while(input[j]){                      //converts to lower case
    				input[j] = tolower(input[j]);
    			    j++;
    			}
    			stringstream ss;
    			ss<<input;
    			ss>>temp;
    			/*hard coded in numbers because it will ALWAYS be "and ",
    			meaning ( will start on space 4
    			and substr the string will be getting rid of those 4 spaces + 2 paranthesis
    			*/
    			//checks if and case and for user syntax
    			if(temp=="and"&&input.find("(")==4&&input.find(")")==input.size()-1){
    				temp = input.substr(5,input.size()-6);
    				char* ctemp;
    				strcpy(ctemp, temp.c_str());	//convert to char* to tokenize
    				char* cword1 = strtok(ctemp,",");	//extract first word
    				string word1(cword1);		//convert char* to string to trim and input into set
    				trim(word1);
    				Set<WebPage> and1 = wpm.get(word1);
    				Set<WebPage> result;
    				cword1 = strtok(NULL,",");	//could just do ", " to get rid of leading white space
    				while(cword1!=NULL){		//but i already made the trim function so too bad
    					string word2(cword1);	//essentially doing what I did above
    					trim(word2);
    					Set<WebPage> and2 = wpm.get(word2);
    					result = and1.setIntersection(and2);	//check for intersections
    					Set<WebPage> and1 = result;		//*** resets and1 to be result thus and2 will check for 
    					cword1 = strtok(NULL,",");		//an intersection of previous words
    				}
    				print(result);
    			}
    			else if(temp=="or"&&input.find("(")==3&&input.find(")")==input.size()-1){
    				temp = input.substr(4,input.size()-5);
    				char* ctemp;
    				strcpy(ctemp, temp.c_str());	//convert to char* to tokenize
    				char* cword1 = strtok(ctemp,",");	//extract first word
    				string word1(cword1);		//convert char* to string to trim and input into set
    				trim(word1);
    				Set<WebPage> and1 = wpm.get(word1);
    				Set<WebPage> result;
    				cword1 = strtok(NULL,",");	//could just do ", " to get rid of leading white space
    				while(cword1!=NULL){		//but i already made the trim function so too bad
    					string word2(cword1);
    					trim(word2);
    					Set<WebPage> and2 = wpm.get(word2);
    					result = and1.setUnion(and2);
    					Set<WebPage> and1 = result;
    					cword1 = strtok(NULL,",");
    				}
    				print(result);
    			}
    			else if(temp == input){
    				Set<WebPage> output = wpm.get(input);
    				print(output);
				}
				else
					cout << endl << "Invalid Input. Try Again" << endl;
			}
			cout << "Thank you! Exiting." << endl;
    		return 0;
    	}
    }
	catch(logic_error &e){
		cout << e.what();
	}
}

void trim(string& word){
	int pos = word.find_first_not_of(" "); //finds extra white space from beginning
    word = word.substr(pos);				//trims
    pos = word.find_last_not_of(" "); //finds trailing white space
    word = word.substr(0, pos+1);			//trims
}

void print(Set<WebPage> web){
	string input;
    //cout << endl;
    for (WebPage* x = web.first(); x!= NULL; x=web.next()){
		cout << *x << endl;
		cin >> input;
		if(input == "quit")
			break;
	}
}