#include "stdafx.h"
// Amusing_num.cpp : Defines the entry point for the console application.
//by :: bu galala

#include <iostream>
#include <algorithm>
#include <string>
using  namespace std;

int n, inp[1000], dignum;
string res[1000], cur = "";

int main() {
	cin >> n;
	for (int i = 0; i < n && cin >> inp[i]; i++);
	for (int i = 0; i < n; i++) {
		int key = inp[i], j;
		dignum = 1;
		cur = res[i];
		for (j = 1; key > pow(2, j); j++)
			key -= pow(2, j);
		dignum = j;
		int tmp = dignum;
		while (cur.size() < tmp) {
			dignum--;
			if (key <= pow(2, dignum))
				cur += '5';
			else {
				cur += '6';
				key -= pow(2, dignum);
			}
		}
		res[i] = cur;
	}
	for (int i = 0; i < n && cout << res[i] << endl; i++);
	return 0;
}

