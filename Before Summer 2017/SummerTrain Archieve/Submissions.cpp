
//	By :: abu_galala

#include <iostream>
#include <vector>
#include <set>
#include <string.h>

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
	scanf("%d\n", &T);
	do {
		memset(dis, -1, sizeof dis);
		memset(arr, 0, sizeof arr);
		memset(C, 0, sizeof C);
		scanf("%d %d %d %d", &n, &m, &s, &e);
		for (int i = 0; i < m; i++) {
			int f = 0, l = 0, c = 0;
			scanf("%d %d %d", &f, &l, &c);
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
// by :: bu_galala

#include <iostream>
#include <set>
#include <vector>

using namespace std;

vector<int> arr[10001];
int cnt[10001], n, m, cur, x, y;
set<int> Ready;
vector<int> res;

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &x, &y);
		arr[x].push_back(y);
		cnt[y]++;
	}
	for (int i = 1; i <= n; i++) {
		if (!cnt[i])
			Ready.insert(i);
	}
	while (Ready.size()) {
		cur = *Ready.begin();
		Ready.erase(*Ready.begin());
		for (int i = 0; i < arr[cur].size(); i++) {
			cnt[arr[cur][i]]--;
			if (!cnt[arr[cur][i]])
				Ready.insert(arr[cur][i]);
		}
		res.push_back(cur);
	}
	if (res.size() != n)
		printf("Sandro fails. \n");
	else {
		for (int i = 0; i < res.size(); i++) {
			printf("%d ",res[i]);
		}
		printf("\n");
	}
	return 0;
}
*/


/*
//  :: by bu_galala

#include <iostream>
#include <string.h>
using namespace std;
int arr[1001][1001], vis[1001][1001], n;

void solve(int x, int y) {
	if (x == n || y == n || x < 0 || y < 0)	return;
	if (vis[x][y] != 0) return;
	vis[x][y] = 1;
	bool flag = 1;
	if (arr[x][y + 1] == arr[x][y]) { flag = 0 ; solve(x, y + 1);}
	if (arr[x + 1][y] == arr[x][y]) { flag = 0 ; solve(x + 1, y);}
	if (arr[x][y - 1] == arr[x][y]) { flag = 0 ; solve(x, y - 1);}
	if (arr[x - 1][y] == arr[x][y]) { flag = 0 ; solve(x - 1, y);}
	if(flag) vis[x][y] = 0;
	return;
}

int main() {
	bool res[1001];
	int cnt = 0;
	//cin >> n;
	scanf("%d",&n);
	do {
		for (int i = 1; i <= (n - 1); i++) {
			int x, y;
			for (int j = 0; j < n; j++) {
				//cin >> x >> y;
				scanf("%d %d", &x,&y);
				arr[x - 1][y - 1] = i;
			}
			solve(x - 1, y - 1);
		}
		res[cnt] = 1;
		bool wrong = 0, flag = 1;
		for (int i = 0; i < n && !wrong; i++) {
			for (int j = 0; j < n; j++) {
				if (flag && arr[i][j] == 0) {
					solve(i, j);
					flag = 0;
				}
				if (vis[i][j] == 0) {
					res[cnt] = 0;
					wrong = 1;
					break;
				}
			}
		}
		cnt++;
		scanf("%d", &n);
		memset(vis, 0, sizeof vis);
		memset(arr, 0, sizeof arr);
	} while (n > 0);
	for (int i = 0; i < cnt; i++) {
		if (res[i])
			cout << "good" << endl;
		else
			cout << "wrong" << endl;
	}
	return 0;
}
*/
