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
//	freopen("alost.in", "r", stdin);
#endif
}
typedef long long int lli;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vector<ii> > vvii;

const lli N = 1e6 + 5;
const lli maxE = 1e5 + 10;
const lli MOD = 1e9 + 7;
const double GOLDEN_RATIO = ((1 + sqrt(5)) / 2);

bool isWin(string c) {
	return (c[0] != '.' and c[0] == c[1] and c[1] == c[2])
			|| (c[3] != '.' and c[3] == c[4] and c[4] == c[5])
			|| (c[6] != '.' and c[6] == c[7] and c[7] == c[8])
			|| (c[0] != '.' and c[0] == c[3] and c[3] == c[6])
			|| (c[1] != '.' and c[1] == c[4] and c[4] == c[7])
			|| (c[2] != '.' and c[2] == c[5] and c[5] == c[8])
			|| (c[0] != '.' and c[0] == c[4] and c[4] == c[8])
			|| (c[2] != '.' and c[2] == c[4] and c[4] == c[6]);
}

int main() {
	file();

	int T;
	cin >> T;
	while (T--) {
		string board = "", r, st = ".........", cur, ans = "no";
		bool player = 1;
		for (int i = 0; i < 3 && cin >> r; board += r, ++i)
			;

		// first way
		/*
		 queue<pair<string, bool>> q;
		 q.push( { st, player });
		 while (q.size()) {
		 cur = q.front().first, player = q.front().second, q.pop();
		 if (cur == board) {
		 ans = "yes";
		 break;
		 }
		 if (isWin(cur))
		 continue;
		 for (int i = 0; i < 9; ++i) {
		 if (cur[i] == '.') {
		 cur[i] = ((player) ? 'X' : 'O');
		 if (cur[i] == board[i])
		 q.push( { cur, (bool) (1 ^ player) });
		 cur[i] = '.';
		 }
		 }
		 }
		 */

		// second way
		queue<string> q;
		q.push(st);
		for (int sz  = 1; !q.empty(); player =(1 ^ player) , sz = q.size())
			while(sz--){
				cur = q.front(),q.pop();
				if(cur == board){
					ans = "yes";
					break;
				}
				if(isWin(cur))
					continue;
				for (int i = 0; i < 9; ++i)
					if(cur[i] == '.'){
						cur[i] = ((player)? 'X':'O');
						if(cur[i] == board[i])
							q.push(cur);
						cur[i] = '.';
					}
			}
		cout << ans << "\n";
	}
	return 0;
}
/*




















 scanf("%[^\n]%c",n);
 */
