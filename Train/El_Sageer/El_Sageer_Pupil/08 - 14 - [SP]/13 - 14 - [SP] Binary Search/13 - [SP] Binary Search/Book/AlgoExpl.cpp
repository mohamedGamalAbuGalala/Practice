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
#define otf(x) printf("%.3lf", x)// output double/float with 0.00
// helpers defines
#define all(v) v.begin(), v.end()
#define sz(v) ((int)((v).size()))	// eg... vector<int> v; sz(v)
#define ssz(s) ((int)strlen(s))		// eg... char s[10];  ssz(s)
#define pb push_back
#define mem(a,b) memset(a,b,sizeof(a))
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
const int MN = 1e6 + 1e2;
const int MW = 1e3 + 5;
typedef long long int lli;
const int OO = 1e9 + 5;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef pair<lli, string> lls;

bool can(double f) {
	double t = f;
	return t >= 0;
}

double IBS(double lo = 0.0, double hi = 10000.0, double mid = 0.0, double ans =
		0.0) {
	for (int i = 0; i < 50; i++) {
		mid = (lo + hi) / 2.0;
		if (can(mid)) {
			ans = mid, hi = mid;
		} else
			lo = mid;
	}
	return ans;
}
double BS(double lo = 0.0, double hi = 10000.0, double mid = 0.0, double ans =
		0.0) {
	while (fabs(hi - lo) > EPS) {
		mid = (lo + hi) / 2.0;
		if (can(mid)) {
			ans = mid;
			hi = mid;
		} else
			lo = mid;
	}
	return ans;
}
int main() {
	file(); // TODO

	return 0;
}
/*
binary_search(A, target):
   lo = 1, hi = size(A)
   while lo <= hi:
      mid = lo + (hi-lo)/2
      if A[mid] == target:
         return mid
      else if A[mid] < target:
         lo = mid+1
      else:
         hi = mid-1

   // target was not found




binary_search(lo, hi, p):
   while lo < hi:
      mid = lo + (hi-lo)/2
      if p(mid) == true:
         hi = mid
      else:
         lo = mid+1

   if p(lo) == false:
      complain                // p(x) is false for all x in S!

   return lo         // lo is the least x for which p(x) is true



// warning: there is a nasty bug in this snippet!
binary_search(lo, hi, p):
   while lo < hi:
      mid = lo + (hi-lo)/2    // note: division truncates
      if p(mid) == true:
         hi = mid-1
      else:
         lo = mid

   if p(lo) == true:
      complain                // p(x) is true for all x in S!

   return lo         // lo is the greatest x for which p(x) is false



///  double
   binary_search(lo, hi, p):
   while we choose not to terminate:
      mid = lo + (hi-lo)/2
      if p(mid) == true:
         hi = mid
      else:
         lo = mid

   return lo // lo is close to the border between no and yes



*Design a predicate which can be efficiently evaluated and
						so that binary search can be applied
*Decide on what you’re looking for and code so that
				the search space always contains that (if it exists)
*If the search space consists only of integers,
					test your algorithm on a two-element set to be sure it doesn’t lock up
*Verify that the lower and upper bounds are not overly constrained:
				it’s usually better to relax them as long as it doesn’t break the predicate

 */
