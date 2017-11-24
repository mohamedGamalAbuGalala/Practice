#include <iostream>
#include <math.h>
using namespace std;
int main() {
	string inp;
	int res = 0;
	cin >> inp;
	int init = 'a';
	for (int i = 0, s = inp.size(); i < s; ++i) {
		int z = abs(inp[i] - init);
		res += (z > 26 - z) ? 26 - z : z;
		init = inp[i];
	}
	cout << res << endl;
	return 0;
}
