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
	int T;
	scanf("%d\n", &T);
	for (int i = 0; i < T; ++i) {
		stack<string> s;
		string inp, tmp;
		getline(cin, inp);
		stringstream ss(inp);
		while (ss >> tmp)
			s.push(tmp);
		while (s.size()) {
			cout << s.top();
			s.pop();
			if (s.size())
				cout << " ";
			else
				cout << "\n";
		}
	}
}
