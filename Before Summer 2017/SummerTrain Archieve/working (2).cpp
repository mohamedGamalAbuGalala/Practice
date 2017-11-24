// working.cpp by Bill Weinman <http://bw.org/>
#include <cstdio>
using namespace std;

int main( int argc, char ** argv ) {
//	cout << "Hello, World!" << endl;
//	cerr << "Hello, World!\n";
//	printf("hello world \n");
	string inputString;
	cout << "Type a String : ";
	getline(cin , inputString);
////	cin>> inputString; 
	cout << "Input is : "  << inputString << endl;
	return 0;
}
