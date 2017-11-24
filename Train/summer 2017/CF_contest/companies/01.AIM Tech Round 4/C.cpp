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
#define all(v) v.begin(), v.end()
#define sz(v) ((int)((v).size()))	// eg... vector<int> v; sz(v)
#define pb push_back
#define in(n) scanf("%d",&n)	//scan int
int i, j, k;
#define forr(i,j, n) for(i = j;i < n;i++)
typedef pair<int, int> ii;
typedef vector<ii> vii;
const int OO = 1e9 + 5;
#define ot(x) printf("%d", x)	//output int
#define in(n) scanf("%d",&n)	//scan int
#define ln() printf("\n")		//output new line
#define sp() printf(" ")		//output single space

////////////////////////////////////////////////////////////////////////////////////////////////
// snippet  ::  dinp , dhelp , dvec , lli , dfor , dcons , dbit
using lli = long long int;
using piv = pair<int, vector<int> >;
int arr[100001], stck[100001];
ii sorted[100];
bool visited[100001];
vector<piv > seq;
piv temp;
void solve(int i) {
	if (visited[i]) {
		seq.pb(temp);
		return;
	} else
		visited[i] = 1;
	temp.first++;
	temp.second.pb(i + 1);
	solve(sorted[i].second);
}
int main() { // dfil
	fl(); //TODO
	int n;
	cin >> n;
	forr(i,0,n and in(arr[i]))
		sorted[i].first = arr[i],sorted[i].second = i;
	sort(sorted, sorted + n);
	forr(i,0,n){
		if (visited[i])
			continue;
		temp.first = 0;
		temp.second.clear();
		solve(i);
	}
	ot(sz(seq)),ln();
	for(auto sq : seq){
		ot(sq.first),sp();
		for(auto qs : sq.second)
			ot(qs),sp();
		ln();
	}
	return 0;
}
