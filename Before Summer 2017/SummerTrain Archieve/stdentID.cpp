// stdentID.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
int main()
{
	int van , c , arr [ 1001 ] , sum =  0,mid=0,out=0;
	scanf_s ("%d %d",&van,&c );
	for ( int j = 0; j < c; j++ ) {
		cin >> arr [ j ];
		sum += arr [ j ];
	}
	bool res = 1 ;
	if ( sum % van == 0 ) {
		mid = sum / van;
		for ( int i = 0; i < c; i++ ) {
			sum -= arr [ i ];
			out += arr [ i ];
			if ( out == mid ) {
				out = 0;
			}
			if ( out>mid ) {
				res = 0;
				break;
			}
		}
	} else {
		res = 0;
	}
	if ( res ) cout << "true" << endl;
	else cout << "false"<< endl;
    return 0;
}

