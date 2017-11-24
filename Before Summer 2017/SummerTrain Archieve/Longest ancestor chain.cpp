// Longest ancestor chain.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

vector<int> arr [ 101 ];

int solve ( int cur ) {
	int ret1 = 0 , ret2 = 0;
	for ( int i = 0; i < arr [ cur ].size ( ); i++ ) {
		ret1 = solve ( arr [ cur ] [ i ] ) + 1;
		ret2 = max ( ret1 , ret2 );
	}
	return ret2;
}
int main ( ) {
	int n , x , y;
	cin >> n;
	for ( int i = 0; i < n; i++ ) {
		cin >> x >> y;

		arr [ y ].push_back ( x );
	}
	int res = solve ( 0 );
	cout << res << endl;
	return 0;
}