#include <bits/stdc++.h>
using namespace std;
// input handle
#define iln() scanf("\n")
#define in(n) scanf("%d",&n)
#define ins(n) scanf("%s",n)
#define inc(n) scanf("%c",&n)
#define inf(n) scanf("%lf",&n)
#define inl(n) scanf("%lld",&n)
#define ot(x) printf("%d", x)
#define sp() printf(" ")
#define ots(x) printf("%s", x)
#define otc(x) printf("%c", x)
#define ln() printf("\n")
#define otl(x) printf("%lld", x)
#define otf(x) printf("%.14lf", x)
// helpers defines
#define all(v) v.begin(), v.end()
#define sz(v) ((int)((v).size()))
#define ssz(s) ((int)strlen(s))
#define pb push_back
#define mem(a,b) memset(a,b,sizeof(a))
//helpers
void file() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#else
	freopen("jumping.in", "r", stdin);	// HERE
#endif
}
// constants
#define EPS 1e-9
#define PI acos(-1.0) // important constant; alternative #define PI (2.0 * acos(0.0))
const int MN = 1e5 + 1e2;
const int MW = 1e3 + 5;
typedef long long int lli;
const int OO = 1e9 + 5;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef pair<lli, string> lls;

vi edge[MN];
int dist[MN], a[MN];
int main() {
	file();
	int T;
	in(T);
	while (T--) {
		int n, now;
		in(n);
		for (int i = 0; i <= n; i++)
			edge[i].clear();
		for (int i = 1; i <= n and in(a[i]); i++) {
			if (i + a[i] <= n)
				edge[i + a[i]].push_back(i);
			if (i - a[i] >= 1)
				edge[i - a[i]].push_back(i);
		}
		fill(dist, dist + MN, OO);
		queue<int> q;
		q.push(n);
		dist[n] = 0;
		while (sz(q)) {
			now = q.front(), q.pop();
			for (auto it : edge[now])
				if (dist[now] + 1 < dist[it])
					dist[it] = dist[now] + 1, q.push(it);
		}
		for (int i = 1; i <= n and ot((dist[i] == OO) ? -1 : dist[i]) and ln();
				i++)
			;
	}
	return 0;
}
