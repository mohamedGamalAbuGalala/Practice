#include <bits/stdc++.h>
using namespace std;
// input handle
#define iln() scanf("\n")
#define in(n) scanf("%d",&n)
#define ins(n) scanf("%s",n)
#define inc(n) scanf("%c",&n)
#define inf(n) scanf("%lf",&n)
#define inl(n) scanf("%lld",&n)
#define ot(x) printf("%d", x)
#define sp() printf(" ")
#define ots(x) printf("%s", x)
#define otc(x) printf("%c", x)
#define ln() printf("\n")
#define otl(x) printf("%lld ", x)
#define otf(x) printf("%.2lf ", x)
// helpers defines
#define all(v) v.begin(), v.end()
#define sz(v) ((int)((v).size()))
#define ssz(s) ((int)strlen(s))
#define pb push_back
#define mem(a,b) memset(a,b,sizeof(a))
//helpers
void file() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
}
// constants
#define EPS 1e-9
#define PI acos(-1.0) // important constant; alternative #define PI (2.0 * acos(0.0))
const int MN = 1e5 + 1e2;
const int MW = 1e3 + 5;
const int OO = 1e9 + 5;
typedef long long int lli;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef pair<lli, string> lls;

int main() {
	file();
	int n, op, x;
	while (in(n) == 1) {
		stack<int> s;
		queue<int> q;
		priority_queue<int> pq;
		bool ss = 1, qq = 1, pqq = 1;
		for (int i = 0; i < n and in(op) and in(x); ++i)
			if (op == 1) {
				if (ss)
					s.push(x);
				if (qq)
					q.push(x);
				if (pqq)
					pq.push(x);
			} else {
				if (ss) {
					if (!sz(s) or s.top() != x)
						ss = 0;
					else
						s.pop();
				}
				if (qq) {
					if (!sz(q) or q.front() != x)
						qq = 0;
					else
						q.pop();
				}
				if (pqq) {
					if (!sz(pq) or pq.top() != x)
						pqq = 0;
					else
						pq.pop();
				}
			}
		if (ss and !qq and !pqq)
			puts("stack");
		else if (!ss and qq and !pqq)
			puts("queue");
		else if (!ss and !qq and pqq)
			puts("priority queue");
		else if (!ss and !qq and !pqq)
			puts("impossible");
		else
			puts("not sure");
	}
	return 0;
}
