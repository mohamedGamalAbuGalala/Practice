//============================================================================
// Name        : calfflac_01.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
using namespace std;
int main() {
	string inp;
	int i, l, r, len = 0, cnt = 0, iO[20000];
	char cO[20000];
	getline(cin, inp);
	for (i = 0; i < inp.size(); ++i) {
		char cur = inp[i];
		if ((cur >= 'A' && cur <= 'Z') || (cur >= 'a' && cur <= 'z')) {
			if (cur >= 'A' && cur <= 'Z')
				cur = cur + 32;
			cO[cnt] = cur;
			iO[cnt++] = i;
		}
	}
	for (i = 0; i < cnt; ++i) {
		int cl = i, cr = i + 1;
		// even
		while (cl >= 0 && cr < cnt && cO[cl] == cO[cr]) {
			if (len < (cr - cl))
				len = cr - cl, l = iO[cl], r = iO[cr];
			cl--, cr++;
		}
		cl = i - 1, cr = i + 1;
		// odd
		while (cl >= 0 && cr < cnt && cO[cl] == cO[cr]) {
			if (len < (cr - cl))
				len = cr - cl, l = iO[cl], r = iO[cr];
			cl--, cr++;
		}
	}
	cout << len + 1 << endl;
	for (i = l; i <= r && cout << inp[i]; i++)
		;
	return 0;
}
