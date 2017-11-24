#include "stdafx.h"
// 1.Don't Get Rocked.cpp : Defines the entry point for the console application.
// By :: Bugalala

#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;

char arr [ 4 ] [ 4 ];

bool Safe ( int x , int y ) {
	// bool top ,right , left , bottom
	// for() >> top >> wall true or >> R false
	// return top && right && left && bottom
	bool top = 1 , right = 1 , left = 1 , bottom = 1;
	for ( int i = 1; y + i < 4; i++ ) {
		if ( arr [ x ] [ y + i ] == 'X' )
			break;
		if ( arr [ x ] [ y + i ] == 'R' )
			right = 0;
	}
	for ( int i = 1; x + i < 4; i++ ) {
		if ( arr [ x + i ] [ y ] == 'X' )
			break;
		if ( arr [ x + i ] [ y ] == 'R' )
			bottom = 0;
	}
	for ( int i = 1; x - i > -1; i++ ) {
		if ( arr [ x - i ] [ y ] == 'X' )
			break;
		if ( arr [ x - i ] [ y ] == 'R' )
			top = 0;
	}
	for ( int i = 1; y - i > -1; i++ ) {
		if ( arr [ x ] [ y - i ] == 'X' )
			break;
		if ( arr [ x ] [ y - i ] == 'R' )
			top = 0;
	}
	return ( top && right && left && bottom );
}

int solve ( int x , int y ) {
	if ( y > 3 )return solve ( x + 1 , 0 );
	if ( x > 3 ) return 0;
	int ret1 = 0 , ret2 = 0;
	if ( arr [ x ] [ y ] == '.' && Safe ( x , y ) ) {
		arr [ x ] [ y ] = 'R';
		ret1 = 1 + solve ( x , y + 1 );
		arr [ x ] [ y ] = '.';
	}
	ret2 = solve ( x , y + 1 );
	ret1 = max ( ret1 , ret2 );
	return ret1;
}

int main ( ) {
	vector<int> res;
	int s;
	while ( scanf_s ( "%d" , &s ) && s != 0 ) {
		memset ( arr , '\0' , sizeof arr );
		for ( int i = 0; i < s; i++ ) {
			scanf_s ( "\n" );
			for ( int j = 0; j < s; j++ ) {
				scanf_s ( "%c" , &arr [ i ] [ j ] );
			}
		}
		scanf_s ( "\n" );
		res.push_back ( solve ( 0 , 0 ) );
	}
	for ( int i = 0; i < res.size(); i++ ) {
		printf ( "%d\n" , res[i] );
	}
	return 0;
}
/*
4
.X..
....
XX..
....
2
XX
.X
3
.X.
X.X
.X.
3
...
.XX
.XX
4
....
....
....
....
0
>>>
5
1
5
2
4
*/