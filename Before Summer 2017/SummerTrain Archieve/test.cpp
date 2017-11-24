//============================================================================
// Name        : test.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string.h>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;

int toInt(string s) {
	int x = 0;
	for (int i = 0; i < s.size(); ++i)
		x = s[i] - '0' + (x * 10);
	return x;
}

int main() {
	string s;
	int all = 0, bigger = -1, original;

	cin >> s;

	original = toInt(s);

	all = s.size();

	for (int i = all - 1; i > 0; --i)
		all *= i;

	do {
		bigger++;
	} while (next_permutation(s.begin(), s.end()));

	cout << all << "   " << bigger << endl;

	double res = (1 / (float) all);

//	cout << res << endl;

	for (int i = 0; i < bigger - 1; ++i)
		res *= (1 / (float) all);
	cout << res;
	return 0;
}
