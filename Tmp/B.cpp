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
#define inc(n) scanf("%c ",&n)	//scan char
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

////////////////////////////////////////////////////////////////////////////////////////////////
// snippet  ::  dinp , dhelp , dvec , lli , dfor , dcons , dbit , def*

int main() { // dfil
	fl(); //TODO
	int a, b, c, d;
	int dx[] = { 1, -1, 0, 0 };
	int dy[] = { 0, 0, 1, -1 };
	string g1[44], g2[44];
	bool vis[44][44];
	in(a), in(b);
	forr(i, 0, a and cin>>g1[i]);
	in(c), in(d);
	forr(i, 0, c and cin>>g2[i]);
	int score = -1;
	forr(i,0,a - c+1)
	{
		forr(j,0,b - d+1)
		{
			int cs = 0;
			bool can = 1;
			mem(vis, 1);
			forr(k,0,c and can)
			{
				forr(l,0,d and can)
				{
					char cg1 = g1[i + k][j + l], cg2 = g2[k][l];
					if (cg2 != '.') {
						can &= (cg1 == '.' or cg2 == '.');
						forr(f,0,4 and can)
						{
							int ti = i + k + dx[f], tj = j + l + dy[f];
							if (ti < a and ti >= 0 and tj < b and tj >= 0) { // ti not in k and tj not in l
								char tg1 = g1[ti][tj];
								if (tg1 != '.' and cg2 == tg1 and vis[ti][tj])
									cs++, vis[ti][tj] = 0;
							}
						}
					}
				}
			}
			if (can)
				score = max(cs, score);
		}
	}
	ot(score);
	return 0;
}
