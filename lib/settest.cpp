#include <iostream>
#include <stdexcept>
#include "set.h"

int main(){
	try{

		Set<int> S;
		if (S.isEmpty())
			cout << "Set S is empty" << endl;
		else
			cout << "Set S is not empty"<< endl;
		S.add(0);
		S.add(1);
		S.add(3);
		S.add(5);
		S.add(7);
		Set<int> Scopy(S);
		cout << "testing first() and next() for SCopy" << endl;
		for (int* x = Scopy.first(); x!= NULL; x=Scopy.next()){
			cout << *x << endl;
		}
		cout << "deleting item 0 (which is at position 0)" <<endl;
		S.remove(0);
		cout << "new first: " << *S.first() <<endl;
		if (S.isEmpty())
			cout << "Set S is empty"<< endl;
		else
			cout << "Set S is not empty"<< endl;
		cout << "testing first() and next() for SCopy" << endl;
		for (int* x = S.first(); x!= NULL; x=S.next()){
			cout << *x << endl;
		}

		Set<int> test;
		test.add(1);
		test.add(5);
		test.add(2);
		test.add(4);
		//setInterection should create a set with numbers 5 and 1

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
		}
	}
	catch(logic_error &e){
		cout << e.what();
	}
	return 0;
}
