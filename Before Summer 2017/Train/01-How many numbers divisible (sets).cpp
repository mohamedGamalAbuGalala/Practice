#include <iostream>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <algorithm>
#include <string.h>
#include <array>
#include <iterator>
#include <set>

#define pb push_back
#define up upper_bound
#define lp lower_bound

using namespace std;

int primes[4] = { 2, 3, 5, 7 };
int n = 100;

int inc_exe(int idx = 0, int d = 1, int sign = -1) {
	if (idx == 4) {
		if (d == 1)
			return 0;
		return sign * n / d;
	}
	return inc_exe(idx + 1, d, sign)
			+ inc_exe(idx + 1, d * primes[idx], sign * -1);
}

int main() {
//	cout<<inc_exe();
	unsigned long int n = 1000000;
	int cnt = 0;
	for (int i2 = 0; i2 < 2; ++i2)
		for (int i3 = 0; i3 < 2; ++i3)
			for (int i5 = 0; i5 < 2; ++i5)
				for (int i7 = 0; i7 < 2; ++i7) {
					int d = 1, elemcnt = 0;

					if (i2)
						d *= 2, elemcnt++;
					if (i3)
						d *= 3, elemcnt++;
					if (i5)
						d *= 5, elemcnt++;
					if (i7)
						d *= 7, elemcnt++;

					if (!elemcnt)
						continue;

					int sign = (elemcnt & 1) ? 1 : -1;

					cnt += sign * n / d;
				}

	cout << cnt;

	return 0;
}
