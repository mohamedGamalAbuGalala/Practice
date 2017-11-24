#include <bits/stdc++.h>
using namespace std;
void fl() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
//	freopen("ot.txt", "w", stdout);
#else
//	freopen("jumping.in", "r", stdin);	// HERE
#endif
}
#define iln() scanf("\n")		//scan new line
#define sp() printf(" ")		//output single space
#define ln() printf("\n")		//output new line
#define in(n) scanf("%d",&n)	//scan int
#define ot(x) printf("%d", x)	//output int
#define ins(n) scanf("%s",n)	//scan char[]
#define ots(x) printf("%s", x)	//output char[]  ( be careful using it may have some issue )
#define inc(n) scanf("%c",&n)	//scan char
#define otc(x) printf("%c", x)	//output char
#define inf(n) scanf("%lf",&n)	//scan double/float
#define otf(x) printf("%.12lf", x)// output double/float with 0.00
#define inl(n) scanf("%lld",&n)	//scan long long int
#define otl(x) printf("%lld", x)//output long long int

#define forr(i,j, n) for(int i = j;i < n;i++)
#define frr(i,j, n) for(int i = j;i >= n;i--)
#define all(v) v.begin(), v.end()
#define sz(v) ((int)((v).size()))	// eg... vector<int> v; sz(v)
#define pb push_back
#define ssz(s) ((int)strlen(s))		// eg... char s[10];  ssz(s)
#define mem(a,b) memset(a,b,sizeof(a))
#define mem3d(dp,b) fill(&dp[0][0][0], &dp[0][0][0] + sizeof(dp) / sizeof(dp[0][0][0]), b)
#define mem2d(dp,b) fill(&dp[0][0], &dp[0][0] + sizeof(dp) / sizeof(dp[0][0]), b)
#define max3(a,b,c) max(a , max(b , c))
#define min3(a,b,c) min(a , min(b , c))
#define F first
#define S second
const int MN = 1e6 + 1e1;
const int OO = 1e9 + 5;
typedef pair<int, int> ii;
typedef vector<ii> vii;

////////////////////////////////////////////////////////////////////////////////////////////////
// snippet  ::  dinp , dhelp , dvec , lli , dfor , dcons , dbit , def*

int n, cns, ans;

char op;
int dp[4][2000];
vii ar;

int slv(int st, int lop, int x) {
	if (x == ans) {
		return 0;
	}
	int &ret = dp[lop][x];
	if (ret == -1) {
		ret = OO;
		forr(i,st,n)
		{
			ii cur = ar[i];
			if (cur.F == 0)
				ret = min(ret, 1 + slv(i + 1, 0, (x & cur.S)));
			else if (cur.F == 1)
				ret = min(ret, 1 + slv(i + 1, 1, (x | cur.S)));
			else
				ret = min(ret, 1 + slv(i + 1, 2, (x ^ cur.S)));
			ret = min(ret, slv(i + 1, lop, x));
		}
	}
	return ret;
}

int main() { // dfil
	fl(); //TODO
	in(n), getchar(), ans = 0, mem(dp, -1);
	int st = -1;
	forr(i,0,n and inc(op) and in(cns) and getchar())
	{
		if (!i) {
			if (op == '&')
				st = 1024;
			else if (op == '|')
				st = 0;
			else
				st = (1024 ^ cns);
		}
		ii cur;
		cur.S = cns;
		if (op == '&')
			ans &= cns, cur.F = 0;
		else if (op == '|')
			ans |= cns, cur.F = 1;
		else
			ans ^= cns, cur.F = 2;
		ar.pb(cur);
	}
	cout << slv(0, 3, st);
	return 0;
}
//			if ((x & i) != x and dp[0][(x & i)] == -1)
//				ret = min(ret, slv(0, x & i) + 1);
//			if ((x | i) != x and dp[1][(x | i)] == -1)
//				ret = min(ret, slv(1, x | i) + 1);
//			if ((x ^ i) != x and dp[2][(x ^ i)] == -1)
//				ret = min(ret, slv(2, x ^ i) + 1);
