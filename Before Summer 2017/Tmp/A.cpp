//============================================================================
// Name        : WorkingUbuntu.cpp
// Author      : buGalala
// Version     :
// Copyright   : @buGalala
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>

#define INF 1e18
#define pb push_back
#define up upper_bound
#define lp lower_bound
#define rep(i,n) fr( __typeof(n)i = 0 ; i < n ; i++)

using namespace std;

typedef long long int lli;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector< vector<ii> > vvii;

const lli maxN = 10000;
const lli maxE = 1e5 + 10;

int main() {
//	freopen("in.txt", "r", stdin);
	int i, j;
	int ar[4][4];
	for (i = 0; i < 4; ++i)
		for (int j = 0; j < 4; ++j)
			cin>>ar[i][j];

	for (i = 0; i < 4; ++i) {
		int p = ar[i][3];
		for (j = 0; j < 3; ++j) {
			int cur = ar[i][j];
			if( p && cur){
				cout<<"YES\n";
				return 0;
			}
		}
	}

	int l1 = ar[0][0], l2 = ar[1][0] , l3 = ar[2][0], l4 = ar[3][0],
		s1 = ar[0][1], s2 = ar[1][1] , s3 = ar[2][1], s4 = ar[3][1],
		r1 = ar[0][2], r2 = ar[1][2] , r3 = ar[2][2], r4 = ar[3][2],
		p1 = ar[0][3], p2 = ar[1][3] , p3 = ar[2][3], p4 = ar[3][3];
	bool res = 0;

	if( (l1 && p4) || (r1 && p2) || (s1 && p3) ) {
		cout<<"YES\n";
		return 0;
	}

	if( (l2 && p1) || (r2 && p3) || (s2 && p4 ) ){
		cout<<"YES\n";
		return 0;
	}

	if( (l3 && p2) || (r3 && p4) || (s3 && p1) ){
		cout<<"YES\n";
		return 0;
	}

	if( (l4 && p3) || (r4 && p1) || (s4 && p2) ){
		cout<<"YES\n";
		return 0;
	}

	cout<<"NO\n";

	return 0;
}
