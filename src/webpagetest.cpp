#include <iostream>
#include <stdexcept>
#include "../webpage.h"

int main(){
	try{
		WebPage w("wptest.txt");
		Set<string> web(w.allWords());
		cout << "hello";
	}
	catch(logic_error &e){
		cout << e.what();
	}
}