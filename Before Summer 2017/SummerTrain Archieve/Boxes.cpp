// Boxes.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct box {
	int a[3];
};

int main()
{
	vector<box> r;
	int n ;
	cin >> n;
	for ( int i = 0; i < n; i++ ) {
		box b ;
		cin >> b.a[0] >> b.a[1] >> b.a[2];
		r.push_back ( b );
	}
	int res = 0 ;
	for ( int i = 0; i < r.size(); i++ ) {
		int  min = r [ i ].a [ 0 ];
		for ( int j = 1; j < 3; j++ ) {
			if ( min > r [ i ].a [ j ] )
				min = r [ i ].a [ j ] ;
		}
		res += min;
	}
	cout << res;
    return 0;
}

