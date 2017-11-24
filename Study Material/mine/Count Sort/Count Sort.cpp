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
#define otl(x) printf("%lld", x)
#define otf(x) printf("%.14lf", x)
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

int L, R, RANGE = 10, K;
void countSort(int arr[]) {
	int output[K] { 0 }, count[K] { 0 }, i;
	// Store count of each num
	for (i = 0; i < RANGE; ++i)
		++count[arr[i] - L];
	// Change count[i] so that count[i] now contains actual
	// position of this num in output array
	for (i = 1; i < K; ++i)
		count[i] += count[i - 1];
	// Build the output num array
	for (i = 0; i < RANGE; ++i)
		output[count[arr[i] - L] - 1] = arr[i], --count[arr[i] - L];
	// Copy the output array to arr, so that arr now
	for (i = 0; i < RANGE; ++i)
		arr[i] = output[i];
}
int main() {
	file();
	int arr[] = { 9, 9, 5, 5, 4, 4, 2, 2, 1, 1 };
	L = 1, R = 9;
	K = R - L + 1;
	countSort(arr);
	for (auto it : arr)
		ot(it), sp();
	return 0;
}

