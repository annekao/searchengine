#include <iostream>
#include <stdexcept>
#include "../webpage.h"

int main(){
	try{
		WebPage w("wptest.txt");
		Set<string> web = w.allWords();
		for (string* x = web.first(); x!= NULL; x=web.next()){
			cout << *x << endl;
		}
		cout << w;

		WebPage w2("wptest2.txt"); //reads in as invalid file???
		cout << w2;
		Set<string> web2 = w2.allWords();
		for (string* x = web2.first(); x!= NULL; x=web2.next()){
			cout << *x << endl;
		}
	}
	catch(logic_error &e){
		cout << e.what();
	}
}