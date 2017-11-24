#include <iostream>
#include <math.h>
using namespace std;
int main() {
	int n, res = 0;
	char ar[50];
	cin >> n;
	for (int i = 0; i < n && cin >> ar[i]; ++i)
		;
	for (int i = 0; i < n - 1; ++i) {
		int l = i - 1, r = i + 1;
		while (ar[i] == ar[r] && i + 1 < n && ar[r] != '.')
			res++, ar[r++] = '.';
		while (ar[i] == ar[l] && i - 1 > -1 && ar[l] != '.')
			res++, ar[l--] = '.';
	}
	cout<<res<<endl;
	return 0;
}
