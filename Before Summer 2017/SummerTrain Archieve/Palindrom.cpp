//============================================================================
// Name        : Palindrom.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
using namespace std;

int main() {
	int i, l, R, n;
	bool res = 1;
	string inp;
	getline(cin, inp);
	n = inp.size();
	l = 0, R = n - 1;
	for (i = 0; i < n; ++i) {
		while (!((inp[l] >= 'a' && inp[l] <= 'z')
				|| (inp[l] >= 'A' && inp[l] <= 'Z')))
			l++;
		while (!((inp[R] >= 'a' && inp[R] <= 'z')
				|| (inp[R] >= 'A' && inp[R] <= 'Z')))
			R--;
		if (l >= R)
			break;
		if (inp[l] >= 'A' && inp[l] <= 'Z')
			inp[l] = inp[l] + 32;
		if (inp[R] >= 'A' && inp[R] <= 'Z')
			inp[R] = inp[R] + 32;
		if (inp[R] != inp[l]) {
			res = 0;
			break;
		}
		l++, R--;
	}
	if (res)
		cout << "true" << endl;
	else
		cout << "false" << endl;
	return 0;
}
