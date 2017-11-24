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
	int n, ar[101], sum = 0, res = 0;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> ar[i], sum += ar[i];
	for (int i = 0; i < n; ++i) {
		int rem = sum - ar[i];
		if(!(rem & 1))
			res++;
	}
	cout<<res<<endl;
	return 0;
}
