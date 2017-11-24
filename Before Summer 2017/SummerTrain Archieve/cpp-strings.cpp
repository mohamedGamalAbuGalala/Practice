/*
// cpp-strings.cpp by Bill Weinman <http://bw.org/>
#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
const int & f(int & i){
	return ++i;
}


int main(int argc, char ** argv) {



//	string cppstring = "This is a C++ string.";


	int i = 5;
//	f(i) = 42;
	printf("%d",i);


//	cout << cppstring << endl;


	 for( unsigned int i = 0; i<  cppstring.size(); i++) {
	 printf("%02d: %c\n", i, cppstring[i]);
	 }



	 for (char c : cppstring)
	 printf("%c \n",c);



	for (auto it = cppstring.begin(); it != cppstring.end(); ++it) {
		printf(" %c\n", *it);
	}


	return 0;
}

*/
