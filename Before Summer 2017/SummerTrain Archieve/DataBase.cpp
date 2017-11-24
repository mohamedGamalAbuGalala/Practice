//============================================================================
// Name        : test_.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <string>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <stdint.h>
#include <typeinfo>
#include <vector>
using namespace std;
//int i[100];
pair<int, int> IC[100001];
bool res[100001];

//int I[10001];
//int C[1001];

bool cmp(pair<int, int> b, pair<int, int> a){
if (b.first < a.first) return 1;
if (b.first == a.first) return b.second < a.second;
return false;
}
int main() {
	cout<<"hello"<<endl;
	int x, n, r, resind = 0, ind = 0;
	cin >> x;
	for (int i = 0; i < x; i++) {
		cin >> n >> r;
		for (int j = 0; j < r; j++) {
			cin >> IC[ind].first >> IC[ind].second;
			ind++;
		}
		int tmp = ind;
		ind -= r;
		res[resind] = true;
		bool wrong = false;
		sort(IC+ind, IC + tmp, cmp);
		for (int j = ind; !wrong && j < tmp -1; j++) {
			for (int k = j +1; k < tmp; k++) {
				if (IC[j].first == IC[k].first) {
					if (IC[j].second == IC[k].second) {
						res[resind] = false;
						wrong = true;
						break;
						//goto aa;
					}
				} else {
					break;
				}
			}
		}
		//aa:
		ind = tmp;
		resind++;
		cout << endl;
	}
	for (int i = 0; i < resind; i++) {
		string tmp = (res[i] == 1) ? "possible" : "Impossible";
		cout << "Scenario#" << i + 1 << ": " << tmp << endl;
	}
	return 0;
}

