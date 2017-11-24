//============================================================================
// Name        : Bitmap.cpp
// Author      : Akram
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <queue>
#include <string.h>
using namespace std;
int res[182][182][182];
char arr[182][182];
struct node {
	int x;
	int y;
	int d;
};

int t, n, m, nn[182], mm[182];
int rx[] = { 1, -1, 0, 0 };
int ry[] = { 0, 0, 1, -1 };
queue<node> Q;
int main() {
	cin >> t;
	node cur;
	memset(res, -1, sizeof res);

	for (int i = 0; i < t; ++i) {
		cin >> n >> m;
		nn[i] = n;
		mm[i] = m;
		//take the value from user
		for (int j = 0; j < n; ++j) {
			for (int k = 0; k < m; ++k) {
				cin >> arr[j][k];
				if (arr[j][k] == '1') {
					cur.x = j;
					cur.y = k;
					cur.d = 0;
					Q.push(cur);
					res[i][j][k] = 0;
				}
			}
		}

		while (Q.size()) {
			cur = Q.front();
			Q.pop();

			res[i][cur.x][cur.y] = cur.d;

			for (int l = 0; l < 4; ++l) {
				node temp;
				temp.x = cur.x + rx[l];
				temp.y = cur.y + ry[l];
				temp.d = cur.d + 1;
				if (temp.x < 0 || temp.x >= n || temp.y < 0 || temp.y >= m)
					continue;
				if (res[i][temp.x][temp.y] != -1)
					continue;
				//res[i][temp.x][temp.y] = temp.d;
				Q.push(temp);
			}
		}

	}
	cout << endl;
	for (int i = 0; i < t; i++) {
		n = nn[i];
		m = mm[i];
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++)
				cout << res[i][j][k] << " ";
			cout << endl;
		}
		cout << endl;
	}

	return 0;
}
