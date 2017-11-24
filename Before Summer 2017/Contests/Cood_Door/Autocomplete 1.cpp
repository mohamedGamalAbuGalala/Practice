// autocomplete.cpp : Defines the entry point for the console application.
//

#include <string>
#include <iostream>

using namespace std;
int main ( ) {
	bool f = 0;
	int c = 0 , cnt = 0;
	string arr [ 1001 ] , cmp;
	//cin >> c;
	scanf ( "%d\n" , &c );
	getline ( cin , cmp );
	for ( int i = 0; i < c; i++ ) {
		getline ( cin , arr [ i ] );
	}
	for ( int i = 0; i < c; i++ ) {
		for ( int j = 0; j < cmp.size ( ); j++ ) {
			if ( arr [ i ] [ j ] == cmp [ j ] ) {
				continue;
			} else {
				f = 1;
				break;
			}
		}
		if ( !f ) cnt++;
		f = 0;
	}
	cout << cnt << endl;
	return 0;
}

