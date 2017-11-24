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

struct node {
	string s;
	int c;
};

node nnode(string n, int c) {
	node nod;
	nod.s = n;
	nod.c = c;
	return nod;
}

bool solved(string n) {
	for (int i = 0; i < (int) n.size(); ++i)
		if (n[i] == '-')
			return 0;
	return 1;
}

int nodeCount;

int k;
map<string, int> mp;
queue<node> q;

bool goood(string s) {
	bool seq = 0, pseql = 0, pseqr = 0;
	int cnt = 0;

	for (int i = 0; i < (int) s.size() && !seq; ++i) {
		if (cnt >= k)
			seq = 1;
		if (s[i] == '-')
			cnt++;
		else
			cnt = 0;
	}
	if (cnt >= k)
		seq = 1;
	cnt = 0;
	for (int i = 0; i < (int) s.size() && !pseql; ++i) {
		if (cnt >= k)
			pseql = 1;
		if (s[i] == '-') {
			cnt++;
			while (++i < (int) s.size() && s[i] == '+')
				cnt++;
			--i;
		}
	}

	cnt = 0;
	for (int i = (int) s.size(); i > -1 && !pseqr; --i) {
		if (cnt >= k)
			pseqr = 1;
		if (s[i] == '-') {
			cnt++;
			while (--i > -1 && s[i] == '+')
				cnt++;
			++i;
		}
	}

	return ((!seq) || (!pseql) || (!pseqr));
}

/*
 2
 ---------- 2
 --------- 3
 */

bool minuses(string s) {
	int cnt = 0;
	for (int i = 0; i < (int) s.size(); ++i) {
		if (s[i] == '-')
			cnt++;
		else
			return 0;
	}
	if (cnt == (int)s.size() && cnt % k == 0)
		return 1;
	return 0;
}

int solve(string s) {
	nodeCount = 0;
	mp.clear();
	mp[s] = 1;
	while (q.size())
		q.pop();

	node n = nnode(s, 0);
	q.push(n);
	while (q.size()) {
		node cur = q.front();
		q.pop();
		if (solved(cur.s))
			return cur.c;
		for (int i = 0; i <= (int) s.size() - k; ++i) {

			string tmp = cur.s;
			for (int j = i; j < (k + i); ++j) {
				if (cur.s[j] == '+')
					tmp[j] = '-';
				else
					tmp[j] = '+';
			}
			map<string, int>::iterator it;
			it = mp.find(tmp);
			if (it != mp.end())
				continue;
			// check for gooodness

			if (!goood(tmp))
				continue;

			mp[tmp] = 1;

			node tmpp = nnode(tmp, cur.c + 1);
			q.push(tmpp);
			nodeCount++;
		}
	}
	return -1;
}

/*
 *
 *
 *
 *those S for which min(LS, RS) is maximal.
 *			those If there is only one such stall,
 *					they choose it;
 *			otherwise,
 *					they choose
 the one among those where
 max(LS, RS) is maximal.
 *
 *	O	. 	.	.	.	O
 *	O	.	O	.	.	O
 *	O	.	O	O	.	O
 *
 *	O	.	.	o	o	.	O
 *
 *
 *	O	.	.	o	.	o	.	O
 *
 */

int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int T, tt = 1, sol;
	string s;
	cin >> T;
	while (T--) {
		cin >> s >> k;
		if (minuses(s))
			sol = (((int) s.size()) / k);
		else
			sol = solve(s);
//					cout << nodeCount<< endl;
		if (sol != -1)
			cout << "Case #" << tt++ << ": " << sol << endl;
		else
			cout << "Case #" << tt++ << ": " << "IMPOSSIBLE" << endl;
	}
	return 0;
}

