#include "stdafx.h"
// highWays.cpp : Defines the entry point for the console application.
//	By :: abu_galala

#include <iostream>
#include <vector>
#include <set>

using namespace std;

class node {
public:
	int ind, cost;
};

bool operator < (node a, node b) {
	if (a.cost != b.cost)
		return a.cost < b.cost;
	else
		return a.ind < b.ind;
}

vector <int> res, arr[100001], C[100001];
int dis[100001], s, e;
set<node> S;

int dijkstra() {
	node cur;
	cur.ind = s;
	cur.cost = 0;
	S.insert(cur);
	while (S.size()) {
		cur = *S.begin();
		S.erase(*S.begin());
		if (dis[cur.ind] != -1) continue;
		dis[cur.ind] = cur.cost;
		if (cur.ind == e) return cur.cost;
		for (int i = 0; i < arr[cur.ind].size(); i++) {
			node tmp;
			tmp.ind = arr[cur.ind][i];
			tmp.cost = cur.cost + C[cur.ind][i];
			S.insert(tmp);
		}
	}
	return -1;
}

int main() {
	int T = 0, n = 0, m = 0;
	scanf_s("%d\n", &T);
	do {
		memset(dis, -1, sizeof dis);
		memset(arr, 0, sizeof arr);
		memset(C, 0, sizeof C);
		scanf_s("%d %d %d %d", &n, &m, &s, &e);
		for (int i = 0; i < m; i++) {
			int f = 0, l = 0, c = 0;
			scanf_s("%d %d %d", &f, &l, &c);
			arr[f].push_back(l);
			C[f].push_back(c);
			arr[l].push_back(f);
			C[l].push_back(c);
		}
		res.push_back(dijkstra());
		T--;
	} while (T>0);
	for (int i = 0; i < res.size(); i++) {
		if (res[i] == -1)
			printf("NONE");
		else
			printf("%d", res[i]);
		printf("\n");
	}
	return 0;
}
/*
#include <iostream>
#include <vector>
#include <set>
using namespace std;

class node {
public:
int ind, cost;
};

bool operator < (node a, node b) {
if (a.cost != b.cost)
return a.cost < b.cost;
else
return a.ind < b.ind;
}

int dis[100001];
vector<int> res;
vector<int> arr[100001];
vector<int> C[100001];
set<node> S;
int T, n, m, s, e;

int dijkstra() {
node cur;
cur.ind = s;
cur.cost = 0;
S.insert(cur);
while (S.size()) {
cur = *S.begin();
S.erase(*S.begin());
if (dis[cur.ind] != -1)	continue;
dis[cur.ind] = cur.cost;
if (cur.ind == e) return cur.cost;
for (int i = 0; i < arr[cur.ind].size(); i++) {
node tmp;
tmp.ind = arr[cur.ind][i];
tmp.cost = cur.cost + C[cur.ind][i];
if (dis[tmp.ind] == -1) S.insert(tmp);
}
}
return -1;
}

int main() {
scanf_s("%d\n", &T);
do {
scanf_s("%d %d %d %d", &n, &m, &s, &e);
memset(arr, 0, sizeof arr);
memset(C, 0, sizeof C);
memset(dis, -1, sizeof dis);
for (int i = 0; i < m; i++) {
int f, l, t;
scanf_s("%d %d %d", &f, &l, &t);
arr[f].push_back(l);
C[f].push_back(t);
arr[l].push_back(f);
C[l].push_back(t);
}
res.push_back(dijkstra());
T--;
} while (T > 0);
for (int i = 0; i < res.size(); i++) {
if (res[i] == -1)
printf("NONE");
else
printf("%d", res[i]);
printf("\n");
}
return 0;
}

*/
/*
n (2 ≤ n ≤ 100000)
m (1 ≤ m ≤ 100000)
the s city and the e city. Cities are numbered from 1 to n
The time(t) will be between 1 and 1000
outPut ::
the minimum time it takes to get from the start to the destination.

TestCases	:::
Input ::
2
4 2 1 4
1 2 5
3 4 5
4 4 1 4
1 2 5
2 3 5
3 4 5
4 2 6
OutPut ::
NONE.
11
*/

