// stdentID.cpp : Defines the entry point for the console application.
//

#include <iostream>
using namespace std;
int main()
{
	int gID , c , arr [ 1001 ];
	scanf ("%d %d",&gID,&c );
	for ( int j = 0; j < c; j++ ) {
		cin >> arr [ j ];
	}
	for ( int  i = 0; i < c; i++ ) {
		if ( gID-arr[i]>0 ) {
			gID -= arr [ i ];
		}
		else { break; }
	}
	cout << gID;
	return 0;
}

