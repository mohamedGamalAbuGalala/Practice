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

#define sp() printf(" ")		//output single space
typedef vector<int> vi;
#define in(n) scanf("%d",&n)	//scan int
#define ot(x) printf("%d", x)	//output int
#define ln() printf("\n")		//output new line
int i, j, k;
#define forr(i,j, n) for(i = j;i < n;i++)
#define frr(i,j, n) for(i = j;i >= n;i--)
#define pb push_back
#define mem(a,b) memset(a,b,sizeof(a))
#define sz(v) ((int)((v).size()))	// eg... vector<int> v; sz(v)
const int OO = 1e9 + 5;
////////////////////////////////////////////////////////////////////////////////////////////////
// snippet  ::  dinp , dhelp , dvec , lli , dfor , dcons , dbit

int main() { // dfil
	fl(); //TODO
	int T;
	in(T), getchar();
	forr(i,0,T)
	{
		stack<string> s;
		string inp, tmp;
		getline(cin, inp);
		stringstream ss(inp);
		while (ss >> tmp)
			s.push(tmp);
		while (sz(s))
			cout << s.top(), s.pop(), (s.size()) ? sp() : ln();
	}
	return 0;
}
