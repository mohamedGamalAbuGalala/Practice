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
#define mem(a,b) memset(a,b,sizeof(a))

////////////////////////////////////////////////////////////////////////////////////////////////
// snippet  ::  dinp , dhelp , dvec , lli , dfor , dcons , dbit , def*

int xx[] { 2, 2, 1, 1, -1, -1, -2, -2 };
int yy[] { 1, -1, 2, -2, 2, -2, 1, -1 };

int main() { // dfil
	fl(); //TODO
	int dst[66][66], x, y, nx, ny;
	mem(dst, 5);
	forr(i,0,64)
	{
		dst[i][i] = 0;
		x = i >> 3, y = i & 7;
		forr(j,0,8)
		{
			nx = x + xx[j], ny = y + yy[j];
			if (nx >= 0 and nx < 8 and ny >= 0 and ny < 8)
				dst[i][(nx * 8) + ny] = 1;
		}
	}
	forr(k,0,64)
		forr(i,0,64)
			forr(j,0,64)
				dst[i][j] = min(dst[i][j], dst[i][k] + dst[k][j]);
	string s, d;
	while (cin >> s >> d)
		printf("To get from %s to %s takes %d knight moves.\n", s.c_str(),
				d.c_str(),
				dst[((s[0] - 'a') * 8 + (s[1] - '1'))][((d[0] - 'a') * 8
						+ (d[1] - '1'))]);

	return 0;
}
