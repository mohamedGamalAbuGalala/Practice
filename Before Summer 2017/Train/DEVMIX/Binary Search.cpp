/*
 Notes::

 Input::
 Output::

 */
#include <bits/stdc++.h>

#define INF 1000000000
#define pb push_back
#define up upper_bound
#define lp lower_bound

using namespace std;

typedef long long int lli;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vector<ii>> vvii;

const lli maxN = 20000 + 10;
const lli maxE = 1e5 + 10;

int main() {
	freopen("in.txt", "r", stdin);
	vector<int> ar;
	int n, k, si;
	cin>>si;
	while (si--){
		cin>>n;
		ar.push_back(n);
	}
	sort(ar.begin(), ar.end());
	cin >> k;
	int s = 0, e = ar.size() - 1;
	while (s < e) {
		int m = (s + e) / 2;
		if (ar[m] > k)
			e = m - 1;
		else if (ar[m] < k)
			s = m + 1;
		else {
			cout << "found";
			return 0;
		}
	}
	cout << "Not found";
}
