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

////////////////////////////////////////////////////////////////////////////////////////////////
// snippet  ::  dinp , dhelp , dvec , lli , dfor , dcons , dbit

int main() { // dfil
	fl(); //TODO
	string n;
	cin >> n;
	int z = 0;
	for (auto ch : n)
		if (ch == '0')
			z++;
		else
			z = 0;
	string zz(z, '0');
	string pal = zz + n;
	string rpal = pal;
	reverse(all(pal));
	if (pal == rpal)
		cout << "YES";
	else
		cout << "NO";
	return 0;
}
