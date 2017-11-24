// 10.culffluc.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <string>

using namespace std;

int main() {
	string inp;
	int l, r, len = 0, cnt = 0, i, j, iO[20000];
	char cO[20000];
	getline(cin, inp);
	for (i = 0; i < inp.size(); ++i) {
		if (((inp[i] >= 'a' && inp[i] <= 'z')
			  || (inp[i] >= 'A' && inp[i] <= 'Z'))) {
			if (inp[i] >= 'A' && inp[i] <= 'Z') {
				char tmp = inp[i] + 32;
				cO[cnt] = tmp;
			} else
				cO[cnt] = inp[i];
			iO[cnt++] = i;
		}
	}
	/*
		cul.,f,..fluc
        dsfljkz.,z/'sdxzmooom
        sdfkjl;kxz/,x'zxlmoooom
        Madam, I'm Adam
	*/

	for (i = 0; i < cnt; ++i) {
		int cl = i, cr = i + 1;
		while (cl >= 0 && cr < cnt && cO[cl] == cO[cr]) {
			if (len < (cr - cl)) {
				len = cr - cl;
				l = cl, r = cr;
			}
			cl--, cr++;
		}
		while (cl >= 0 && cr < cnt && cO[cl - 1] == cO[cr]) {
			if (len < (cr - (cl - 1))) {
				len = cr - (cl - 1);
				l = cl - 1, r = cr;
			}
			cl--, cr++;
		}
	}
	printf("%d\n", len + 1);
	for (i = iO[l]; i <= iO[r]; ++i)
		printf("%c", inp[i]);
	printf ( "\n" );
	return 0;
}
