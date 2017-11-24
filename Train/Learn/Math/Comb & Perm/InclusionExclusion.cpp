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

const lli N = 1e2;
const lli maxE = 1e5 + 10;
const lli MOD = 1e9 + 7;
const double GOLDEN_RATIO = ((1 + sqrt(5)) / 2);

//	inclusion Exclusion_01
/*
 int primes[] = { 2, 3, 5, 7 };
 int n = 1e2;
 int inc_excl(int ind = 0, int d = 1 , int s = -1) {
 if (ind == 4) {
 if (d == 1)
 return 0;
 return s * n / d;
 }
 int ret1, ret2;
 ret1 = inc_excl(ind + 1, d, s);
 ret2 = inc_excl(ind + 1, d * primes[ind], s * -1);
 return ret1 + ret2;
 }
 */

//	inclusion Exclusion_01
int primes[] = { 2, 3, 8, 10 };	// we can't take 8,10 because they are devisible by 2
vi res;
int n = 1e2;
int inc_excl(int ind = 0, int d = 1, int s = -1) {
	if (ind == (int) res.size()) {
		if (d == 1)
			return 0;
		return s * n / d;
	}
	int excl, incl;
	excl = inc_excl(ind + 1, d, s);
	incl = inc_excl(ind + 1, d * res[ind], s * -1);
	return excl + incl;
}

void checkdivisors() {
	for (int i = 0; i < 4; ++i) {
		bool dev = 0;
		for (int j = 0; j < 4; ++j) {
			if (i == j)
				continue;
			if (!(primes[i] % primes[j]))
				dev = 1;
		}
		if (!dev)
			res.pb(primes[i]);
	}
}

int main() {
	freopen("in.txt", "r", stdin);

	//	cout<<inc_excl();		//01	numbers is devisible
	//	cout<< n - inc_excl();		//01.1  numbers is not devisible

	checkdivisors();		// to get ride of divisible numbers in the set ex. 8 , 2 ( 8 is divisible by 2 )
	cout << inc_excl();		//02

	return 0;
}
