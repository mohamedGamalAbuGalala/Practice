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

const int maxh = 205;
const int maxw = 205;

char bin[256][5];

int H, W, pic[maxh][maxw], color[maxh][maxw];
char line[maxw];

void decode(char ch, int row, int col) {
	for (int i = 0; i < 4; i++)
		pic[row][col + i] = (bin[(int) ch][i] - '0');
}

const int dr[] = { -1, 1, 0, 0 };
const int dc[] = { 0, 0, -1, 1 };

void dfs(int row, int col, int c) {
	if (row < 0 or row >= H or col < 0 or col >= W)
		return;
	color[row][col] = c;
	for (int i = 0; i < 4; i++) {
		int row2 = row + dr[i], col2 = col + dc[i];
		if (pic[row2][col2] == pic[row][col] and !color[row2][col2])
			dfs(row2, col2, c);
	}
}

vector<set<int>> neighbors;

void checkNeighbors(int row, int col) {
	for (int i = 0; i < 4; i++) {
		int row2 = row + dr[i], col2 = col + dc[i];
		if (row2 >= 0 and row2 < H and col2 >= 0 and col2 < W
				and !pic[row2][col2] and color[row2][col2] != 1)
			neighbors[color[row][col]].insert(color[row2][col2]);
		// store in each shape how many white areas are around...
	}
}

const string code = "WAKJSD";

char recognize(int c) {
	int cnt = neighbors[c].size();
	return code[cnt];
}

void init() {
	strcpy(bin['0'], "0000");
	strcpy(bin['1'], "0001");
	strcpy(bin['2'], "0010");
	strcpy(bin['3'], "0011");
	strcpy(bin['4'], "0100");
	strcpy(bin['5'], "0101");
	strcpy(bin['6'], "0110");
	strcpy(bin['7'], "0111");
	strcpy(bin['8'], "1000");
	strcpy(bin['9'], "1001");
	strcpy(bin['a'], "1010");
	strcpy(bin['b'], "1011");
	strcpy(bin['c'], "1100");
	strcpy(bin['d'], "1101");
	strcpy(bin['e'], "1110");
	strcpy(bin['f'], "1111");
}

int main() {				// basic flood fill
	file(); // TODO
	init();
	int kase = 0;
	while (in(H) == 1 and in(W) == 1 and H and W) {
		mem(pic, 0);
		for (int i = 0; i < H and ins(line); i++)
			for (int j = 0; j < W; j++)
				decode(line[j], i + 1, j * 4 + 1);

		H += 2, W = W * 4 + 2;

		int cnt = 0;
		vector<int> cc;
		mem(color, 0);
		for (int i = 0; i < H; i++)
			for (int j = 0; j < W; j++)
				if (!color[i][j]) {
					dfs(i, j, ++cnt);
					if (pic[i][j] == 1)
						cc.push_back(cnt);
				}
		neighbors.clear(), neighbors.resize(cnt + 1);
		for (int i = 0; i < H; i++)
			for (int j = 0; j < W; j++)
				if (pic[i][j] == 1)
					checkNeighbors(i, j);

		vector<char> ans;
		for (auto it : cc)
			ans.push_back(recognize(it));
		sort(ans.begin(), ans.end());
		printf("Case %d: ", ++kase);
		for (auto it : ans)
			otc(it);
		ln();
	}
	return 0;
}
