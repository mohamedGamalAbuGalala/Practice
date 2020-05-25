#include <bits/stdc++.h>

using namespace std;
void fl()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
//	freopen("ot.txt", "w", stdout);
#else
//	freopen("strings.in", "r", stdin);	// HERE
#endif
}
#define iln() scanf("\n")		   //scan new line
#define sp() printf(" ")		   //output single space
#define ln() printf("\n")		   //output new line
#define in(n) scanf("%d", &n)	   //scan int
#define ot(x) printf("%d", x)	   //output int
#define ins(n) scanf("%s", n)	   //scan char[]
#define ots(x) printf("%s", x)	   //output char[]  ( be careful using it may have some issue )
#define inc(n) scanf("%c ", &n)	   //scan char
#define otc(x) printf("%c", x)	   //output char
#define inf(n) scanf("%lf", &n)	   //scan double/float
#define otf(x) printf("%.12lf", x) // output double/float with 0.00
#define inl(n) scanf("%lld", &n)   //scan long long int
#define otl(x) printf("%lld", x)   //output long long int
#define all(v) v.begin(), v.end()
#define sz(v) ((int)((v).size())) // eg... vector<int> v; sz(v)
#define pb push_back
#define ssz(s) ((int)strlen(s)) // eg... char s[10];  ssz(s)
#define mem(a, b) memset(a, b, sizeof(a))
#define mem3d(dp, b) fill(&dp[0][0][0], &dp[0][0][0] + sizeof(dp) / sizeof(dp[0][0][0]), b)
#define mem2d(dp, b) fill(&dp[0][0], &dp[0][0] + sizeof(dp) / sizeof(dp[0][0]), b)
#define max3(a, b, c) max(a, max(b, c))
#define min3(a, b, c) min(a, min(b, c))
#define F first
#define S second
#define forr(i, j, n) for (int i = j; i < n; i++)
#define frr(i, j, n) for (int i = j; i >= n; i--)

////////////////////////////////////////////////////////////////////////////////////////////////
// snippet  ::  dinp , dhelp , dvec , lli , dfor , dcons , dbit , def*
const int MN = 1e6 + 1e1;
const int OO = 1e9 + 5;
typedef vector<int> vi;
typedef vector<vi> vvi;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};
int ddd[] = {0, 1, 2, 3};

int n, m, k, ma, ans, a[52][52];
char x;
vector<pair<int, pair<int, int>>> v;
int flood(int i, int j, int c)
{
	if (i < 1 or i > n or j < 1 or j > m)
		return 0;
	if (!a[i][j] or a[i][j] == c)
		return 0;
	if (i == 1 or i == n or j == 1 or j == m)
		return -10000;
	a[i][j] = c;
	int ret = 1;
	for (auto it : ddd)
		ret += flood(i + dx[it], j + dy[it], c);
	return ret;
}

int main()
{		  // dfil
	fl(); //TODO
	in(n), in(m), in(k), iln();
	forr(i, 1, n + 1)
	{
		forr(j, 1, m + 1 and inc(x)) if (x == '.')
			a[i][j] = -1;
		iln();
	}
	forr(i, 1, n + 1)
		forr(j, 1, m + 1) if (a[i][j] == -1)
			v.push_back({flood(i, j, ++ma), {i, j}});
	sort(all(v));
	forr(i, 0, ma - k)
	{
		if (v[i].first < 0)
			continue;
		ans += v[i].first;
		flood(v[i].second.first, v[i].second.second, 0);
	}
	ot(ans), ln();
	forr(i, 1, n + 1)
	{
		forr(j, 1, m + 1)
				a[i][j]
			? otc('.')
			: otc('*');
		ln();
	}
	return 0;
}
