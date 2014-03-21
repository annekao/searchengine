#include <iostream>
#include <stdexcept>
#include "../lib/stlset.h"

int main(){
	try{
		Set<int> S;
		if (S.empty())
			cout << "Set S is empty" << endl;
		else
			cout << "Set S is not empty"<< endl;
		S.insert(0);
		S.insert(1);
		S.insert(3);
		S.insert(5);
		S.insert(7);

		Set<int> Scopy(S);

		cout << "testing first() and next() for SCopy" << endl;
		for (Set<int>::iterator it = Scopy.begin(); it!=Scopy.end(); ++it){
			cout << *it << endl;
		}
		/*cout << "deleting item 0 (which is at position 0)" <<endl;
		S.erase(0);
		cout << "new first: " << *S.begin() <<endl;
		if (S.empty())
			cout << "Set S is empty"<< endl;
		else
			cout << "Set S is not empty"<< endl;
		cout << "testing first() and next() for S" << endl;
		for (Set<string>::iterator it = S.begin(); it!=S.end(); ++it){
			cout << *it << endl;
		}

		Set<int> test;
		test.insert(1);
		test.insert(5);
		test.insert(2);
		test.insert(4);*/
		//setInterection should create a set with numbers 5 and 1
/*
		Set<int> resultI;
		cout << "Testing setIntersection: " << endl;
		resultI = S.setIntersection(test);
		for (int* x = resultI.first(); x!= NULL; x=resultI.next()){
			cout <<*x <<endl;
		}

		//should result in 1, 2, 3, 4, 5, 7
		Set<int> resultU;
		cout << "Testing setUnion: " << endl;
		resultU = S.setUnion(test);
		for (int* x = resultU.first(); x!= NULL; x=resultU.next()){
			cout <<*x <<endl;
		}*/
	}
	catch(logic_error &e){
		cout << e.what();
	}
	return 0;
}
