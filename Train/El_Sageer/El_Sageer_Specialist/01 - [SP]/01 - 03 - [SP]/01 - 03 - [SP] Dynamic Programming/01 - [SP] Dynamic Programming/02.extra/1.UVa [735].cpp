#include <bits/stdc++.h>
using namespace std;
void fl() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("ot.txt", "w", stdout);
#else
//	freopen("jumping.in", "r", stdin);	// HERE
#endif
}
#define forr(zzz,j, n) for(int zzz = j;zzz < n;zzz++)
#define all(v) v.begin(), v.end()
#define sz(v) ((int)((v).size()))	// eg... vector<int> v; sz(v)
#define pb push_back

////////////////////////////////////////////////////////////////////////////////////////////////
// snippet  ::  dinp , dhelp , dvec , lli , dfor , dcons , dbit

int main() { // dfil
	fl(); //TODO
	int N;
	while (cin >> N and N > 0) {
		using lli = long long int;
		lli per = 0, com = 0;
		set<int> sc;
		forr(i,0,21)
			sc.insert(i), sc.insert(i * 2), sc.insert(i * 3);
		sc.insert(50);
		for (auto a : sc)
			for (auto b : sc)
				for (auto c : sc)
					if (a + b + c == N) {
						per++;
						if (b >= a and c >= b)
							com++;
					}

		if (!per)
			printf(
					"THE SCORE OF %d CANNOT BE MADE WITH THREE DARTS.\n**********************************************************************\n",
					N);
		else
			printf(
					"NUMBER OF COMBINATIONS THAT SCORES %d IS %lld.\nNUMBER OF PERMUTATIONS THAT SCORES %d IS %lld.\n**********************************************************************\n",
					N, com, N, per);
	}
	puts("END OF OUTPUT");
	return 0;
}
