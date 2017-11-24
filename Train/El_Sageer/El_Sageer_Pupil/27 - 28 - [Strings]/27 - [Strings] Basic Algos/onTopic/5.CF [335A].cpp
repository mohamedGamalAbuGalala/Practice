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
#define in(n) scanf("%d",&n)	//scan int
#define ot(x) printf("%d", x)	//output int
#define sp() printf(" ")		//output single space
#define ln() printf("\n")		//output new line
int i, j, k;
#define sz(v) ((int)((v).size()))	// eg... vector<int> v; sz(v)
#define pb push_back
#define forr(i,j, n) for(i = j;i < n;i++)
typedef vector<int> vi;
////////////////////////////////////////////////////////////////////////////////////////////////
// snippet  ::  dinp , dhelp , dvec , lli , dfor , dcons , dbit
using lli = long long int;
lli n, m;
vi v;
int arr[27];
string s;
bool ok(float mid) {
	int sum = 0;
	if (mid == 0)
		return 0;
	forr(i,0,26)
		sum += ceil(arr[i] / mid);
	if (sum > n)
		return 0;
	return 1;
}

int main() { // dfil
	fl(); //TODO
	cin >> s >> n;
	int cnt = 0;
	for (auto i : s) {
		arr[i - 'a']++;
		if (arr[i - 'a'] == 1)
			cnt++;
	}
	if (cnt > n)
		return ot(-1), 0;
	int l = 0, r = 2000, ans = 2000;
	while (l < r) {
		int mid = (l + r) / 2;
		if (ok(mid))
			ans = mid, r = mid - 1;
		else
			l = mid + 1;
	}
	while (ok(ans))
		ans--;
	ans++, ot(ans), ln();
	string answer = "";
	forr(i,0,26)
	{
		int c = ceil(arr[i] / (double) ans);
		forr(j,0,c)
			answer += (i + 'a');
	}
	while (sz(answer) < n)
		answer.pb('a');
	cout << answer;
	return 0;
}
