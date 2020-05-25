#include <bits/stdc++.h>
using namespace std;

// helpers defines
#define all(v) v.begin(), v.end()
#define sz(v) ((int)((v).size())) // eg... vector<int> v; sz(v)
#define ssz(s) ((int)strlen(s))   // eg... char s[10];  ssz(s)
#define pb push_back
#define mem(a, b) memset(a, b, sizeof(a))
#define max3(a, b, c) max(a, max(b, c))
#define min3(a, b, c) min(a, min(b, c))
// helpers
void file() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("ot.txt", "w", stdout);
#else
//	freopen("jumping.in", "r", stdin);	// HERE
#endif
}
#define sz(v) ((int)((v).size())) // eg... vector<int> v; sz(v)

typedef long long int lli;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

int i, j, k;

#define forr(i, j, n) for (i = j; i < n; i++)
#define frr(i, j, n) for (i = j; i >= n; i--)

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

int generalizedGCD(int num, int *arr) {
  // WRITE YOUR CODE HERE

  int res = arr[0];
  forr(i, 1, num) {
    res = gcd(arr[i], res);

    if (res == 1)
      return 1;
  }
  return res;
}

int main() {
  file(); // TODO

  return 0;
}
