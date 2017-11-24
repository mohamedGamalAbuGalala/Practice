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
#define ln() printf("\n")		//output new line
#define sp() printf(" ")		//output single space
#define in(n) scanf("%d",&n)	//scan int
#define ot(x) printf("%d", x)	//output int
#define forr(i,j, n) for(int i = j;i < n;i++)
#define mem3d(dp,b) fill(&dp[0][0][0], &dp[0][0][0] + sizeof(dp) / sizeof(dp[0][0][0]), b)
#define sz(v) ((int)((v).size()))	// eg... vector<int> v; sz(v)
#define EPS 1e-9

////////////////////////////////////////////////////////////////////////////////////////////////
// snippet  ::  dinp , dhelp , dvec , lli , dfor , dcons , dbit

struct point_i {
	int x, y;
};

double dst(point_i p1, point_i p2) {
	return hypot(p1.x - p2.x, p1.y - p2.y);
}

int n, l1, l2, x, y, tt;
point_i p[101];
double dist[101][101], dp[101][101][5];
stack<int> s1, s2;

double Btsp(int p1, int p2, int cp) {
	int v = max(p1, p2) + 1;
	if (v == n - 1)
		return dist[p1][v] + dist[v][p2];
	double &ret = dp[p1][p2][cp];
	if (ret < -0.5) {
		ret = 1e16;
		if (v == l1 or v == l2) {
			if (!(cp & 1))
				ret = dist[p1][v] + Btsp(v, p2, cp | 1);
			if (!(cp & 2))
				ret = min(ret, dist[v][p2] + Btsp(p1, v, cp | 2));
		} else
			ret = min(dist[p1][v] + Btsp(v, p2, cp),
					dist[v][p2] + Btsp(p1, v, cp));
	}
	return ret;
}

void print(int p1, int p2, int cp) {
	int v = max(p1, p2) + 1;
	if (v == n - 1) {
		s1.push(v);
		return;
	}
	double opt = Btsp(p1, p2, cp);
	if (v == l1 or v == l2) {
		if (!(cp & 1) and abs(dist[p1][v] + Btsp(v, p2, cp | 1) - opt) < EPS)
			s1.push(v), print(v, p2, cp | 1);
		else if (!(cp & 2)
				and abs(dist[v][p2] + Btsp(p1, v, cp | 2) - opt) < EPS)
			s2.push(v), print(p1, v, cp | 2);
	} else if (abs(dist[p1][v] + Btsp(v, p2, cp) - opt) < EPS)
		s1.push(v), print(v, p2, cp);
	else if (abs(dist[v][p2] + Btsp(p1, v, cp) - opt) < EPS)
		s2.push(v), print(p1, v, cp);
}

int main() { // dfil
	fl(); //TODO
	while (in(n) and in(l1) and in(l2) and n) {
		mem3d(dp, -1);
		forr(i, 0, n and in(p[i].x) and in(p[i].y));
		forr(i,0,n)
			forr(j,0,n)
				dist[i][j] = dist[j][i] = dst(p[i], p[j]);
		printf("Case %d: %.2lf\n", ++tt, Btsp(0, 0, 0)), s1.push(0), s2.push(0), print(
				0, 0, 0);
		while (sz(s1))
			s2.push(s1.top()), s1.pop();
		while (sz(s2) > 1)
			ot(s2.top()), sp(), s2.pop();
		ot(s2.top()), ln(), s2.pop();
	}
	return 0;
}
