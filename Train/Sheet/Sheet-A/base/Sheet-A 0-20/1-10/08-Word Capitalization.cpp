#include <iostream>
#include <math.h>
using namespace std;
int main() {
	string inp;
	cin >> inp;
	if (inp[0] >= 'a' && inp[0] <= 'z')
		inp[0] += 'A' - 'a';
	cout << inp;
	return 0;
}
