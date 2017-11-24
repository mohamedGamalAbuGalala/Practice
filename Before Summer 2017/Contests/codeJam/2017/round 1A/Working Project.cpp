#include <bits/stdc++.h>

#define INF 1e6
#define pb push_back
#define up upper_bound
#define lp lower_bound
#define rep(i,n) fr( __typeof(n)i = 0 ; i < n ; i++)

using namespace std;

typedef long long int lli;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vector<ii>> vvii;

const lli maxN = 10e6 * 4;
const lli maxE = 1e5 + 10;

char ar[26][26];

int di[] = { 0, 0, 1, -1 };
int dj[] = { 1, -1, 0, 0 };

int r, c;

int crow(int s, int i, int j, char cc) {
	int ret = 0;
	for (int ii = s; ii < i; ++ii) {
		if (ar[ii][j] != '?')
			return 0;
		ret++;
	}
	return ret;
}
int ccol(int s, int i, int j, char cc) {
	int ret = 0;
	for (int ii = s; ii < j; ++ii) {
		if (ar[i][ii] != '?')
			return 0;
		ret++;
	}
	return ret;
}
void mrow(int s, int i, int j, char cc) {
	for (int ii = s; ii < i; ++ii) {
		ar[ii][j] = cc;
	}
}
void mcol(int s, int i, int j, char cc) {
	for (int ii = s; ii < j; ++ii) {
		ar[i][ii] = cc;
	}
}

void flood(int i, int j) {
	char cur = ar[i][j];
	int ii = i + 1, jj = j + 1;
	char tmp = ar[ii][jj];
	bool s = 0;
	while (ii < r && jj < c && tmp != cur && tmp == '?' && crow(0, ii, jj, tmp)
			&& ccol(0, ii, jj, tmp)) {
		s = 1;
		ar[ii][jj] = cur;
		mrow(0, ii, jj, cur);
		mcol(0, ii, jj, cur);
		ii++, jj++;
		tmp = ar[ii][jj];
	}
	ii = i - 1, jj = j - 1;
	tmp = ar[ii][jj];
	while (ii > -1 && jj > -1 && tmp != cur && tmp == '?'
			&& crow(0, ii, jj, tmp) && ccol(0, ii, jj, tmp)) {
		s = 1;
		ar[ii][jj] = cur;
		mrow(0, ii, jj, cur);
		mcol(0, ii, jj, cur);
		ii++, jj++;
		tmp = ar[ii][jj];
	}
	if (!s) {
		ii = i + 1, jj = j;
		tmp = ar[ii][jj];
		int rr = crow(0,ii, jj, cur);
		ii = i, jj = j + 1;
		int ll = ccol(0,ii, jj, cur);
		if (rr > ll)
			mrow(0,i + 1, j, cur);
		else
			mcol(0,i, j + 1, cur);
	}

}

int main() {
	freopen("in.txt", "r", stdin);
	int T, t = 1;
	cin >> T;
	map<char, int> v;
	while (T--) {
		scanf("%d %d\n", &r, &c);
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				scanf("%c", &ar[i][j]);
			}
			scanf("\n");
		}
		for (int i = 0; i < r; ++i) {
			for (int j = 0; j < c; ++j) {
				if (ar[i][j] != '?' && v[ar[i][j]] != 1) {
					flood(i, j);
					v[ar[i][j]] = 1;
				}
			}
		}
		cout << "Case #" << t++ << ":\n";
		for (int i = 0; i < r; ++i) {
			cout << ar[i] << "\n";
		}
	}
	return 0;
}

