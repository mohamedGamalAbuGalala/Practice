// DQuery.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
///DQuery (BIT)

#include<algorithm>
#include<stdio.h>
#include<vector>
#include<map>
#include<set>
#include<string.h>
using namespace std;
#define pb push_back

class node {
public:
	int e, i;
};

int n, m;
int ber[30004], flag[1000004], bit[30004], ret[200004];
vector<node> ss;
vector< vector<node> > s(30004, ss);
node cur, dd;

int solve(int en) {
	int i, ret = 0;
	for (i = en; i > 0; i -= (i & -i))
		ret += bit[i];
	return ret;
}

void update(int ind) {
	if (ind == -1) return;
	int i;
	for (i = ind; i <= n; i += (i & -i))
		bit[i]++;
	return;
}

int main() {
	int i, a;
	scanf_s("%d", &n);
	memset(ber, -1, sizeof ber);
	for (i = 0; i<n; i++) {
		scanf_s("%d", &a);
		if (flag[a] == 0) {
			update(i + 1);
			flag[a] = i + 1;
		}
		else ber[flag[a]] = i + 1, flag[a] = i + 1;
	}
	scanf_s("%d", &m);
	for (i = 0; i<m; i++) {
		scanf_s("%d %d", &a, &cur.e);
		cur.i = i;
		s[a].pb(cur);
	}
	for (i = 0; i<30004; i++) {
		for (a = 0; a<s[i].size(); a++)
			ret[s[i][a].i] = solve(s[i][a].e) - solve(i - 1);
		update(ber[i]);
	}
	for (i = 0; i<m; i++)
		printf("%d\n", ret[i]);
	return 0;
}