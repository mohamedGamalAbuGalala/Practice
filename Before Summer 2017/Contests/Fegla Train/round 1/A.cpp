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

void file() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
#else
// online submission
	freopen("airport.in", "r", stdin);
#endif
}
typedef long long int lli;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vector<ii> > vvii;

const lli N = 1e2;
const lli maxE = 1e5 + 10;
const lli MOD = 1e9 + 7;
const double GOLDEN_RATIO = ((1 + sqrt(5)) / 2);

int main() {
	file();
	lli T;
	cin >> T;
	while (T--) {
		int nn = 0, bags = 0, total = 0, width = 0, lenbags[5] = { 0 },
				boxlen[15] = { 0 }, boxWidth[15] = { 0 }, boxp[15] = { 0 },
				ret = 0, indexes[15] = { 0 };
		cin >> nn >> bags >> width;

		for (int i = 0; i < nn; i++) {
			int tmp;
			cin >> tmp;
			total += tmp;
			lenbags[i] = tmp;
		}

		for (int i = 0; i < bags; ++i) {
			int tmp1, tmp2, tmp3;
			cin >> tmp1 >> tmp2 >> tmp3;
			boxlen[i] = tmp1, boxWidth[i] = tmp2, boxp[i] = tmp3;
			indexes[i] = i;
		}

		do {
			int perm = 0, len = 0, weight = 0, i = 0;
			for (int j = 0; j < nn; j++) {
				len = 0;
				while (i < bags) {
					weight += boxWidth[indexes[i]];
					len += boxlen[indexes[i]];
					if (len <= lenbags[j]) {
						if (weight <= width) {
							perm += boxp[indexes[i]];
							i++;
						} else
							break;
					} else {
						weight -= boxWidth[indexes[i]];
						break;
					}
				}
				if (weight <= width)
					continue;
				break;
			}
			ret = max(ret, perm);
		} while (next_permutation(indexes, indexes + bags));

		cout << ret << "\n";
	}
	return 0;
}
