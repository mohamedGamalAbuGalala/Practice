//============================================================================
// Name        : Working.cpp
// Author      : abu-galala
// Version     :
// Copyright   : @bu_galala
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>
#include <string>

#define INF 1e18
#define pb push_back
#define up upper_bound
#define lp lower_bound
#define rep(i,n) fr( __typeof(n)i = 0 ; i < n ; i++)

using namespace std;

void file() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
#else
// online submission
//	freopen("alost.in", "r", stdin);
#endif
}
typedef long long int lli;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vector<ii> > vvii;

const lli N = 2e8 + 5;
const lli maxE = 1e5 + 10;
const lli MOD = 1e9 + 7;
const double GOLDEN_RATIO = ((1 + sqrt(5)) / 2);

lli res = 0;

void slv(string n){
	lli m = (int)n.size();
	if(m == 1){
		 cout<<res;return;
	}
	lli ret = 0;
	string nn;
	for (lli i = 0; i < m; ++i)
		ret += n[i] - '0';
	nn = to_string(ret);
	res++;
	slv(nn);
}

int main() {
	file();
	string n ;
	cin>>n;
	slv(n);
	return  0;
}
