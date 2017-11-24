#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <string.h>
#include <array>
#include <iterator>

#define pb push_back
#define up upper_bound
#define lp lower_bound

using namespace std;
int main() {
	int n, ar[101], ind;
	cin >> n;
	for (int i = 0; i < n && cin >> ar[i]; ++i)
		;
	sort(ar, ar+n);
	auto iterator = up(ar, ar+n, ar[0]);
	ind = iterator - begin(ar);
	if (ind >= n)
		cout << "NO" << endl;
	else
		cout << ar[ind] << endl;
	return 0;
}
