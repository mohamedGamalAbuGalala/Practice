//============================================================================
// Name        : Working.cpp
// Author      : abu-galala
// Version     :
// Copyright   : @bu_galala
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
typedef vector<vector<ii> > vvii;

const lli maxN = 10000;
const lli maxE = 1e5 + 10;
const lli MOD = 1e9 + 7;
const double GOLDEN_RATIO = ((1 + sqrt(5)) / 2);

lli getFib75(int n){
	return (pow(GOLDEN_RATIO,n) - (pow(-GOLDEN_RATIO,-n)))/ sqrt(5);
}

lli fib [102];

lli calcFib(int n = 100){
	if(fib[n])
		return fib[n];
	if(n == 0 || n == 1)
		return 1;
	fib[n-1] = calcFib(n-1) , fib[n-2] =calcFib(n-2);
	return fib[n] = fib[n-1] + fib[n-2];
}

int main() {
	freopen("in.txt", "r", stdin);

	fib[0] =1 , fib[1]=1;
	calcFib();

//	for (int i = 0; i < 100; ++i) {
//		cout<<fib[i]<<" ";
//	}
//	cout<<"\n";

	int n ;
	cin>>n;
	for (int i = 0; i < n; ++i) {
		lli fib75 = getFib75(i+1);
		if(fib75 == fib[i])
			continue;
		cout<<i<<"\n";
		break;
	}

	return 0;
}
