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

//#define f first
//#define s second

string grid[102];
int TC, R, C, row, col;

int dr[] = { 1, 1, 0, -1, -1, -1, 0, 1 };
int dc[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int ddd[] = { 0, 1, 2, 3, 4, 5, 6, 7 };

int floodfill(int r, int c, char c1, char c2) {
	if (r < 0 or r >= R or c < 0 or c >= C or grid[r][c] != c1)
		return 0;
	grid[r][c] = c2;
	int ans = 1;
	for (auto d : ddd)
		ans += floodfill(r + dr[d], c + dc[d], c1, c2);
	return ans;
}

int main() {
	file(); // TODO
	in(TC), getchar(), getchar();
	while (TC--) {
		R = 0, getline(cin, grid[R]), R++;
		while (grid[R - 1][0] == 'L' or grid[R - 1][0] == 'W')
			getline(cin, grid[R]), R++;
		C = sz(grid[0]), R--;
		while (1) {
			stringstream sst;
			sst << grid[R];
			sst >> row >> col, row--, col--;
			ot(floodfill(row, col, 'W', '.')), ln(), floodfill(row, col,
					'.', 'W');
			getline(cin, grid[R]);
			if (grid[R] == "")
				break;
		}
		if (TC)
			ln();
	}
	return 0;
}
