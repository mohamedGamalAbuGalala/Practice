#include <iostream>
#include <math.h>
using namespace std;
int main() {
	int inp, i, j, res, found = 0;
	for (i = 0; i < 5 && !found; i++)
		for (j = 0; j < 5 && !found; j++) {
			cin >> inp;
			if (inp) {
				found = 1;
			}
		}
	i-- , j --;
	res = abs((2 - i)) + abs((2 - j));
	cout << res << endl;
	return 0;
}
