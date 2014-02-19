#include <iostream>
#include <stdexcept>
#include "../webpage.h"

int main(){
	try{
		WebPage w("data/wptest.txt");
		Set<string> web = w.allWords();
		for (string* x = web.first(); x!= NULL; x=web.next()){
			cout << *x << endl;
		}
		cout << w;

		WebPage w2("data/wptest2.txt"); //reads in as invalid file???
		cout << w2;
		Set<string> web2 = w2.allWords();
		for (string* x = web2.first(); x!= NULL; x=web2.next()){
			cout << *x << endl;
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