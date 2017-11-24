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
#define forr(i,j, n) for(int i = j;i < n;i++)
#define frr(i,j, n) for(int i = j;i >= n;i--)
#define in(n) scanf("%d",&n)	//scan int
#define ot(x) printf("%d", x)	//output int
#define mem(a,b) memset(a,b,sizeof(a))

////////////////////////////////////////////////////////////////////////////////////////////////
// snippet  ::  dinp , dhelp , dvec , lli , dfor , dcons , dbit

bool v[212345];
int a[212345];
int n, k, sh, m, ans;

bool tryy(int idx) {
	int kk = 0;
	mem(v, 1);
	forr(i, 1, idx+1)
		v[a[i]] = 0;
	int c = 0;
	forr(i,1,n+1)
	{
		if (v[i])
			c++;
		else
			c = 0;
		if (c == sh)
			c = -1, kk++;
	}
	return kk >= k;
}

int main() { // dfil
	fl(); //TODO
	cin >> n >> k >> sh >> m;
	forr(i, 1, m+1 and in(a[i]));
	int l = 1, h = m;
	while (l < h) {
		int mid = (l + h) / 2;
		if (!tryy(mid))
			h = mid;
		else
			l = mid + 1;
	}
	if(tryy(l))
		l++;
	cout << (l > m ? -1 : l);
	return 0;
}
