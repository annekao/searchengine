#include <iostream>
#include <stdexcept>
#include "../webpage.h"

int main(){
	try{
		WebPage w("data/wptest.txt");
		Set<string> web = w.allWords();
		for (Set<string>::iterator it = web.begin(); it!=web.end(); ++it){
			cout << *it << endl;
		}
		cout << w;

		WebPage w2("data/wptest2.txt"); //reads in as invalid file???
		cout << w2;
		Set<string> web2 = w2.allWords();
		for (Set<string>::iterator it = web2.begin(); it!=web2.end(); ++it){
			cout << *it << endl;
		}
		//Part 4
		//Map<string, List<webpages>>
		//represented using file names
		//hello P1, P2
		//List<webpages> should spit out everything in the file 
		//associated with the string using operator<<

		//ostream (polymorphism)
		// derivations: cout, ofstream, sstream
		// using the <<operator, it can print out to cout, ofile, ss 
		//depending on main
	}
	catch(logic_error &e){
		cout << e.what();
	}
}