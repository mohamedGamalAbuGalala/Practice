#include <bits/stdc++.h>
using namespace std;
// input handle
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
#define ssz(ss) ((int)strlen(s))
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
const int MN = 1e4 + 1e5;
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
	map<string, pair<string, int> > words;
	map<string, pair<string, int> >::const_iterator itr;
	vector<string> result;
	string word, wordSorted;
	cin >> word;
	while (word != "#") {
		wordSorted = word;
		transform(all(wordSorted), wordSorted.begin(), ::toupper);
		sort(all(wordSorted));
		words[wordSorted].first = word, words[wordSorted].second++;
		cin >> word;
	}
	for (itr = words.begin(); itr != words.end(); ++itr)
		if (itr->second.second == 1)
			result.push_back(itr->second.first);
	sort(all(result));
	for (int i = 0; i < sz(result); ++i)
		cout << result[i] << endl;
	return 0;
}
