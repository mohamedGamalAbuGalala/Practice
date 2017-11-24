#include <iostream>
#include <math.h>
using namespace std;
int main() {
	int n, cups = 0, crimes = 0, inp, res = 0;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> inp;
		(inp > 0) ? cups += inp : crimes += inp;
		cups += crimes, crimes = 0;
		if (cups < 0)
			res += (-cups), cups = 0;
	}
	cout << res;
	return 0;
}
