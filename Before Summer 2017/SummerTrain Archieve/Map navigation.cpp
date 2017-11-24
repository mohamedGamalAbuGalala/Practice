// Map navigation.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <string>

using namespace std;

int main ( ) {
	bool f , U , R , D , L ;
	string p1 , p2;
	int n , i , j , x , y;
	cin >> p1 >> p2 >> n;
	U = 1 , R = 0 , D = 0 , L = 0 , f = 1;
	x = 0 , y = 0;
	for ( i = 0; i < n; i++ ) {
		string p ;
		if ( f ) p = p1;
		else p = p2;
		f = !( f );
		for ( j = 0; j < p.size ( ); j++ ) {
			char t = p [ j ];
			if ( t == 'f' ) {
				if ( U ) y ++;
				if ( R ) x++;
				if ( D ) y --;
				if ( L ) x--;
			}
			if ( t == 'r' ) {
				if ( U ) { U = 0 , R = 1;  continue; }
				if ( R ) { R = 0 , D = 1;  continue; }
				if ( D ) { D = 0 , L = 1;  continue; }
				if ( L ) { L = 0 , U = 1;  continue; }
			}
			if ( t == 'l' ) {
				if ( U ) { U = 0 , L = 1;  continue; }
				if ( L ) { L = 0 , D = 1;  continue; }
				if ( D ) { D = 0 , R = 1;  continue; }
				if ( R ) { R = 0 , U = 1;  continue; }
			}
		}
	}
	cout << x << " " << y;
	return 0;
}

