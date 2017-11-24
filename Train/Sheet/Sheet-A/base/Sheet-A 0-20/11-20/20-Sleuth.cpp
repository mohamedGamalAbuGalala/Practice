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
int main() {
	bool res = 0;
	string inp;
	getline(cin, inp);
	for (int i = inp.size() - 1; i >= 0 && !res; --i) {
		char cur = inp[i];
		if ((cur >= 'a' && cur <= 'z') || (cur >= 'A' && cur <= 'Z')) {
			cur = tolower(cur);
			if (cur == 'a' || cur == 'e' || cur == 'i' || cur == 'o'
					|| cur == 'u' || cur == 'y')
				res = 1;
			break;
		}
	}
	if(res)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
	return 0;
}
