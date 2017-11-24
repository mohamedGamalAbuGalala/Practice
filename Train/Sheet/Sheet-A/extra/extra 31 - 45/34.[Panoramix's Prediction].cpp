#include <bits/stdc++.h>
using namespace std;
void fl() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
//	freopen("ot.txt", "w", stdout);
#else
//	freopen("jumping.in", "r", stdin);	// HERE
#endif
}
#define all(v) v.begin(), v.end()
#define sz(v) ((int)((v).size()))	// eg... vector<int> v; sz(v)
#define pb push_back

////////////////////////////////////////////////////////////////////////////////////////////////
// snippet  ::  dinp , dhelp , dvec , lli , dfor , dcons , dbit

typedef vector<int> vi;
bitset<66> bs;
vi primes;

void sieve() {
	bs.set();
	bs[0] = bs[1] = 0;
	for (int i = 2; i <= 60; i++)
		if (bs[i]) {
			for (int j = i * i; j <= 60; j += i)
				bs[j] = 0;
			primes.pb(i);
		}
}

int main() { // dfil
	fl(); //TODO
	int n, m;
	cin >> n >> m, sieve();
	auto f = find(all(primes), n) - primes.begin();
	if (primes[f + 1] == m)
		puts("YES");
	else
		puts("NO");
	return 0;
}
