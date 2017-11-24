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
	string a, b;
	int T;
	in(T);
	while (T-- and cin >> a >> b) {
		char mna = a[0], mxb = b[0];
		int idma = 0;
		forr(i,1,sz(a))
			if (a[i] < mna)
				mna = a[i], idma = i;
		forr(i,1,sz(b))
			mxb = max(mxb, b[i]);
		if (mna >= mxb) {
			puts("impossible");
			continue;
		}
		string ans = "";
		int ft = 0;
		forr(i,0,sz(a))
		{
			bool ldon = 0;
			string ca = a;
			if (ca[i] <= mxb) {
				ca.erase(ca.begin() + i);
				forr(j,0,sz(ca) and !ldon)
				{
					if (ca[j] <= mxb) {
						ca.insert(ca.begin() + j, mxb);
						ldon = 1;
					}
				}
			}
			if (sz(ca) < sz(a))
				ca.pb(mxb);
			if (!ft)
				ans = ca, ft++;
			else if (ca > ans)
				ans = ca;
		}
		if (sz(ans) < sz(a)) {
			a.erase(a.begin() + idma);
			a.pb(mxb);
			cout << a << "\n";
		} else
			cout << ans << "\n";
	}
	return 0;
}
