#include <bits/stdc++.h>
using namespace std;
// input handle
#define iln() scanf("\n")		//scan new line
#define in(n) scanf("%d",&n)	//scan int
#define ins(n) scanf("%s",n)	//scan char[]
#define inc(n) scanf("%c ",&n)	//scan char
#define inf(n) scanf("%lf",&n)	//scan double/float
#define inl(n) scanf("%lld",&n)	//scan long long int
#define ot(x) printf("%d", x)	//output int
#define sp() printf(" ")		//output single space
#define ots(x) printf("%s", x)	//output char[]  ( be careful using it may have some issue )
#define otc(x) printf("%c", x)	//output char
#define ln() printf("\n")		//output new line
#define otl(x) printf("%lld", x)//output long long int
#define otf(x) printf("%.9lf", x)// output double/float with 0.00
// helpers defines
#define all(v) v.begin(), v.end()
#define sz(v) ((int)((v).size()))	// eg... vector<int> v; sz(v)
#define ssz(s) ((int)strlen(s))		// eg... char s[10];  ssz(s)
#define pb push_back
#define mem(a,b) memset(a,b,sizeof(a))
#define max3(a,b,c) max(a , max(b , c))
#define min3(a,b,c) min(a , min(b , c))
//helpers
void file() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
//	freopen("ot.txt", "w", stdout);
#else
//	freopen("jumping.in", "r", stdin);	// HERE
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
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };
#define ff first
#define ss second
#define WH -1
#define BL 1

char grid[11][11];
int N;

bool valid(int x, int y, int i) {
	return x != -1 && y != -1 && x != N && y != N
			&& (grid[x][y] == '.' || grid[x][y] - 'A' == i);
}

int main() {
	file(); //TODO

	int tt = 1;
	while (1) {
		in(N), getchar();
		int x = -1, y = -1;
		if (N == 0)
			break;
		int n = 0;
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N and inc(grid[i][j]); ++j)
				if (isalpha(grid[i][j])) {
					n = max(n, grid[i][j] - 'A');
					if (grid[i][j] == 'A')
						x = i, y = j;
				}

		int count = 1, min = 0;
		for (int i = 1; i <= n; ++i) {
			int dist[11][11] { 0 }, paths[11][11] { 0 };
			dist[x][y] = paths[x][y] = 1;
			queue<ii> q;
			q.push(ii(x, y));
			grid[x][y] = '.';
			x = -1, y = -1;
			while (sz(q)) {
				ii cur = q.front();
				int &curD = dist[cur.ff][cur.ss], &curP = paths[cur.ff][cur.ss];
				q.pop();
				if (grid[cur.ff][cur.ss] - 'A' == i)
					x = cur.ff, y = cur.ss;

				for (int k = 0; k < 4; ++k) {
					int nxtX = cur.ff + dx[k], nxtY = cur.ss + dy[k];
					if (valid(nxtX, nxtY, i)) {
						int &nxtD = dist[nxtX][nxtY], &nxtP = paths[nxtX][nxtY];
						if (!nxtD)
							nxtD = curD + 1, nxtP = curP, q.push(ii(nxtX, nxtY));
						else if (nxtD == curD + 1)
							nxtP += (curP % 20437);
					}
				}
			}

			if (x == -1) {
				count = -1;
				break;
			}

			min += dist[x][y] - 1;
			count = (count * paths[x][y]) % 20437;
		}

		if (count == -1)
			printf("Case %d: Impossible\n", tt++);
		else
			printf("Case %d: %d %d\n", tt++, min, count);
	}
	return 0;
}
