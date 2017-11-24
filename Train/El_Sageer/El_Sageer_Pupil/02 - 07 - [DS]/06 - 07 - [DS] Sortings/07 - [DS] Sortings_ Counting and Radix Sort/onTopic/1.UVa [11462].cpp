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
const int MN = 2e6 + 1e2;
const int MW = 1e3 + 5;
const int OO = 1e9 + 5;
typedef long long int lli;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef pair<lli, string> lls;

void csort(int array[], const int end, const int max, const int min) {
	const int range = max - min + 1;
	int count[range + 1], scratch[end], i;

	for (i = 0; i < range + 1; i++)
		count[i] = 0;

	/* Set the value of count[i] to the number of
	 * elements in array with value i+min-1. */
	for (i = 0; i < end; i++) {
		int c = array[i] + 1 - min;
		count[c]++;
	}

	/* Update count[i] to be the number of
	 * elements with value less than i+min. */
	for (i = 1; i < range; i++)
		count[i] += count[i - 1];

	/* Copy the elements of array into scratch in
	 * stable sorted order. */
	for (i = (end - 1); i >= 0; i--) {
		int c = array[i] - min;
		int s = count[c];
		scratch[s] = array[i];
		/* Increment count so that the next element
		 * with the same value as the current element
		 * is placed into its own position in scratch. */
		count[c]++;
	}

	for (i = 0; i < end; i++)
		array[i] = scratch[i];
}
int main() {
	file();
	int n;
	while (in(n) and n) {
		int arr[n + 10] { 0 };
		int L = OO, R = -1;
		for (int i = 0; i < n and in(arr[i]);
				R = max(R, arr[i]), L = min(L, arr[i]), ++i)
			;
		csort(arr, n, R, L);

		for (int i = 0; i < n; ++i)
			(i < n - 1) ? ot(arr[i]), sp() : ot(arr[i]);
		ln();
	}
	return 0;
}
