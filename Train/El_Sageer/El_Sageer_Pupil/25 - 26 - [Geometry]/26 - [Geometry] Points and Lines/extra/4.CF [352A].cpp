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
#define otf(x) printf("%.12lf", x)// output double/float with 0.00
// helpers defines
#define all(v) v.begin(), v.end()
#define sz(v) ((int)((v).size()))	// eg... vector<int> v; sz(v)
#define ssz(s) ((int)strlen(s))		// eg... char s[10];  ssz(s)
#define pb push_back
#define mem(a,b) memset(a,b,sizeof(a))
#define max3(a,b,c) max(a , max(b , c))
#define min3(a,b,c) min(a , min(b , c))
#define ff first
#define ss second
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
const int MN = 1e6 + 1e1;
typedef long long int lli;
const int OO = 1e9 + 5;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
int i, j, k;
#define forr(i,j, n) for(i = j;i < n;i++)
#define frr(i,j, n) for(i = j;i >= n;i--)

int main() {
	file(); //TODO
	int n, fv = 0, zr = 0, x;
	in(n);
	forr(i,0,n and in(x))
		(x == 5) ? fv++ : zr++;
	if (!zr)
		ot(-1);
	else if (fv < 9)
		ot(0);
	else {
		fv /= 9;
		forr(i , 0 , fv)
			forr(j,0,9)
				ot(5);
		forr(i,0,zr)
			ot(0);
	}
	return 0;
}
