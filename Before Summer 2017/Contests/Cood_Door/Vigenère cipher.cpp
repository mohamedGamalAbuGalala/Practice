// Vigenère cipher.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>
using namespace std;
int main ( ) {
	int cur = 0;
	string key , inp;
	char alpha [ 29 ];
	alpha [ 0 ] = 'a';
	for ( char i = 1; i < 26; i++ ) {
		alpha [ i ] = 'a' + i;
	}
	alpha [ 26 ] = ' ';
	alpha [ 27 ] = ',';
	alpha [ 28 ] = '.';
	cin >> key  ;
	scanf ( "\n" );
	getline ( cin , inp );

	for ( int i = 0; i < inp.size ( ); i++ ) {
		int ind , k;
		//for input
		if ( inp [ i ] >= 'A' && inp [ i ] <= 'Z' )
			inp [ i ] = inp [ i ] + 32;
		if ( inp [ i ] >= 'a' && inp [ i ] <= 'z' ) {
			ind = inp [ i ] - 'a';
		} else if ( inp [ i ] == ' ' )
			ind = 26;
		else if ( inp [ i ] == ',' )
			ind = 27;
		else if ( inp [ i ] == '.' )
			ind = 28;
		// for key
		if ( key [ cur ] >= 'A' && key [ cur ] <= 'Z' )
			key [ cur ] = key [ cur ] + 32;
		if ( key [ cur ] >= 'a' && key [ cur ] <= 'z' ) {
			k = key [ cur ] - 'a'+ 1;
		} else if ( key [ cur ] == ' ' )
			k = 27;
		else if ( key [ cur ] == ',' )
			k = 28;
		else if ( key [ cur ] == '.' )
			k = 29;
		// get the new shifted index
		int res = ind + k ;
		if ( res  >= 29 )
			res = res % 29;
		inp [ i ] = alpha [ res ];
		cur++;
		if ( cur == key.size ( ) )
			cur = 0;
	}

	cout << inp << endl;
	return 0;
}
