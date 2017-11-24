#include <bits/stdc++.h>
using namespace std;
int t, n, cnttt, cnt3;
char arr[501][501];

int di[] = { 1, -1, 0, 0 };
int dj[] = { 0, 0, 1, -1 };
int valid(int i, int j) {
	return i >= 0 && i < 2 && j >= 0 && j < n && arr[i][j] == '#';
}
int BFS(int x, int y, int cntt) {
	int vis[501][501] = { 0 };
	int cnt = 0, cnt2 = 0;
	cnt3 = 0;
	queue<pair<int, int> > q;
	q.push(make_pair(x, y));
	vis[x][y] = 1;
	while (!q.empty()) {
		int i = q.front().first, j = q.front().second;
		q.pop();
		cnt3++;
		vis[i][j] = 1;
		if (cnt2 == 4 && cnt == 0) {
			return 0;
		}
		cnt = 0;
		cnt2 = 0;
		for (int z = 0; z < 4; z++) {
			int id = i + di[z];
			int jd = j + dj[z];
			if (valid(id, jd) && !vis[id][jd]) {
				q.push(make_pair(id, jd));
				cnt++;
			} else {
				cnt2++;
			}
		}
	}
	if (cnt3 == cntt)
		return true;
	else
		return false;
}
int main() {
	freopen("out.txt", "w", stdout);
	freopen("in.txt", "r", stdin);
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 0; i < 2; i++) {
			scanf("%s", arr[i]);
		}
		int x, y, flag = 0, cnttt = 0;
		for (int i = 0; i < 2; i++) {
			if (flag) {
				break;
			}
			for (int j = 0; j < n; j++) {
				if (arr[i][j] == '#') {
					x = i;
					y = j;
					flag = 1;
					break;
				}

			}
		}
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < n; j++) {
				if (arr[i][j] == '#') {
					cnttt++;
				}
			}
		}
		if (cnttt == 2 * n) {
			printf("%s", "yes\n");
			continue;
		}
		if (!BFS(x, y, cnttt)) {
			printf("%s", "no\n");
		} else {
			printf("%s", "yes\n");

		}
	}

}
