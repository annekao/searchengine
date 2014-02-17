#include <iostream>
#include <stdexcept>
#include "set.h"

int main(){
	try{
		/*Set<int> S;
		S.add(0);
		S.add(1);
		cout << "testing fdirst() and next()" << endl;
		for (int* x = S.first(); x!= NULL; x=S.next()){
			cout << *x << endl;
		}
		//S.remove(0);
		//cout << *S.first();
*/
		List<int> L;
		L.insert(0,0);
		L.insert(1,1);
		//L.remove(0);
		//cout << L.get(0);
	}
	catch(logic_error &e){
		cout << e.what();
	}
	return 0;
}