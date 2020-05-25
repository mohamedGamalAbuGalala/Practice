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

int main() {
  file(); // TODO

  int *states;
  int days = 2;

  int oldSize = sizeof(states);

  while (days--) {
    vi newStates;
    newStates.push_back(0);
    forr(i, 0, oldSize) newStates.push_back(states[i]);
    newStates.push_back(0);

    vi retStates(newStates);

    forr(i, 1, oldSize + 1) if (newStates[i + 1] == newStates[i - 1])
        retStates[i] = 0;
    else retStates[i] = 1;

    forr(i, 1, oldSize + 1) states[i - 1] = retStates[i];
  }
  vi retStates;

  forr(i, 0, oldSize) retStates.push_back(states[i]);

  // return retStates;

  return 0;
}
