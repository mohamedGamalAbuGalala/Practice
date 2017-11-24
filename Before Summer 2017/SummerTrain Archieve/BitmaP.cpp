#include "stdafx.h"
// BitmaP.cpp : Defines the entry point for the console application.
// by :: abu_galala

#include <iostream>
#include <string.h>
#include <algorithm>
#include <queue>

using namespace std;

class node {
public:
	int x, y, d;
};

int dis[182][182][182];

int main() {
	queue<node> Q;
	char arr[182][182];
	int rx[] = { 1, -1, 0, 0 }, ry[] = { 0, 0, 1, -1 }, n, m, t = 0, nn[182], mm[182], temp = 0;
	node cur;
	cin >> t;
	temp = t;
	memset(dis, -1, sizeof dis);
	do {
		cin >> n >> m;
		nn[t] = n; mm[t] = m;
		for (int i = 0; i < n; i++)
			cin >> arr[i];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr[i][j] == '0') continue;
				cur.x = i;
				cur.y = j;
				cur.d = 0;
				dis[t][i][j] = 0;
				Q.push(cur);
			}
		}
		while (Q.size()) {
			cur = Q.front();
			Q.pop();
			dis[t][cur.x][cur.y] = cur.d;
			for (int i = 0; i < 4; i++) {
				node tmp;
				tmp.x = cur.x + rx[i];
				tmp.y = cur.y + ry[i];
				tmp.d = cur.d + 1;
				if (tmp.x < 0 || tmp.y < 0 || tmp.y >= m || tmp.x >= n)
					continue;
				if (dis[t][tmp.x][tmp.y] != -1)
					continue;
				dis[t][tmp.x][tmp.y] = tmp.d;
				Q.push(tmp);
			}
		}
		t--;
	} while (t>0);
	cout << endl;
	for (int i = temp; i >0; i--) {
		n = nn[i]; m = mm[i];
		for (int k = 0; k < n; k++) {
			for (int j = 0; j < m; j++)
				cout << dis[i][k][j] << " ";
			cout << endl;
		}
		cout << endl;
	}
	return 0;
}

/*
2
3 4
0001
0011
0110
3 4
0001
0011
0110
>>

3 2 1 0
2 1 0 0
1 0 0 1

3 2 1 0
2 1 0 0
1 0 0 1

*/