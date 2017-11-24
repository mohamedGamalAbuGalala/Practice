//============================================================================
// Name        : culfluc.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <stdio.h>
#include <iostream>
#include <string>
#include<string.h>

using namespace std;

int main() {

	/*
	 cul.,f,..fluc
	 cul.,f,..fluc Madam, I'm Adam
	 dsfljkz.,z/'sdxzmooom
	 sdfkjl;kxz/,x'zxlmoooom
	 Madam, I'm Adam
	 */
	string inp;
	char charO[10000], cur;
	int indO[10000], i = 0, l, r, cl, cr, cnt = 0, len = 0;
	cin >> inp;

	for (i = 0; i < inp.length(); i++) {
		cur = inp[i];
		if ((cur <= 'z' && cur >= 'a') || (cur <= 'Z' && cur >= 'A')) {
			if ((cur <= 'Z' && cur >= 'A')) {
				cur -= 32;
			}
			charO[cnt] = cur;
			indO[cnt] = i;
			cnt++;
		}
	}

	for (i = 0; i < cnt; i++) {
		cl = i, cr = i + 1; // even
		while (cl >= 0 && cr < cnt && charO[cl] == charO[cr]) {
			if (len < (cr - cl)) {
				len = cr - cl, l = cl, r = cr;
			}
			cl--, cr++;
		}
		cl = i - 1, cr = i + 1;  // odd
		while (cl >= 0 && cr < cnt && charO[cl] == charO[cr]) {
			if (len < (cr - cl)) {
				len = cr - cl, l = cl, r = cr;
			}
			cl--, cr++;
		}
	}

	cout << len + 1 << endl;

	for (i = indO[l]; i <= indO[r]; i++) {
		cout << inp[i];
	}

	return 0;
}
