/*
// working.cpp by Bill Weinman <http://bw.org/>
#include <iostream>
#include <typeinfo>
#include <vector>
using namespace std;

int func(){
	return 42;
}

int main( int argc, char ** argv ) {

	vector<int> i = {1 , 2 , 3 , 4 , 5};
	for (auto it = i.begin(); it != i.end(); ++it) {
		cout<< *it <<endl;
	}

	cout << "working.cpp" << endl;
	auto x = func();
	cout<< x <<endl;
	cout<<typeid(x).name()<<endl;
	return 0;
}
*/
