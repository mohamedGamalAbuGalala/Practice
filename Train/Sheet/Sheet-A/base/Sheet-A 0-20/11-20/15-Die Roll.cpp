#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <string.h>

#define pb push_back
#define up upper_bound
#define lp lower_bound

using namespace std;
int main() {
	int y, w, num = 0, den = 6;
	cin >> y >> w;
	num = max(y, w) - 1;
	num = 6 - num;
	if (num == 0)
		cout << "0/1" << endl;
	else if (num == 6)
		cout << "1/1" << endl;
	else {
		int gcd = __gcd(num , den);
		while (gcd != 1) {
			num /= gcd;
			den /= gcd;
			gcd = __gcd(num , den);
		}
		cout << num << "/" << den << endl;
	}
	return 0;
}
