#include <bits/stdc++.h>

#define INF 1e6
#define pb push_back
#define up upper_bound
#define lp lower_bound
#define rep(i,n) for( __typeof(n)i = 0 ; i < n ; i++)

using namespace std;

typedef long long int lli;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vector<ii>> vvii;

const lli maxN = 20000 + 10;
const lli maxE = 1e5 + 10;

char hexaaa[] { 'A', 'B', 'C', 'D', 'E' };

string itoa(int n, int s) {
	string ret = "";
	while (n != 0) {
		char in = n % s + '0';
		if (in > '9')
			in = hexaaa[(in - ('9' + 1))];
		ret = in + ret;
		n /= s;
	}
	return ret;
}

bool pal(string inp) {
	int s = 0, e = inp.size() - 1;
	while (s < e) {
		if (inp[s] != inp[e])
			return 0;
		s++, e--;
	}
	return 1;
}

int main() {
	freopen("in.txt", "r", stdin);
	int n, ret = 0;
	string sret;
	scanf("%d", &n);

	sret = itoa(n, 2);
	if (pal(sret))
		ret += 2;

	sret = itoa(n, 8);
	if (pal(sret))
		ret += 4;

	sret = itoa(n, 10);
	if (pal(sret))
		ret += 1;

	sret = itoa(n, 16);
	if (pal(sret))
		ret += 8;

	cout << ret;
	return 0;
}

