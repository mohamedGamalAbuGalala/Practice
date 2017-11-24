//============================================================================
// Name        : Blown.cpp
// Author      : abu-galala
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	cout << "Kruskal_Algorithm" << endl; // prints Kruskal_Algorithm
	string inp;
	cin >> inp;
	int arr[100], l = inp.length(), i, j, r = 0, b = 0, y = 0, g = 0;
//	cout<<inp<<"  "<<l;

	for (i = 0; i + 4 < l; i++) {
		int rd = 0, bl = 0, yl = 0, gn = 0;
		for (j = 0; j < 4; ++j) {
			char cur = inp[i + j];
			if (cur == 'R')
				rd = j;
			else if (cur == 'B')
				bl = j;
			else if (cur == 'Y')
				yl = j;
			else if (cur == 'G')
				gn = j;
		}
		for (j = 0; j < 4; ++j) {
			char cur = inp[i + j];
			if (cur  == '!') {
				if (!rd){
					r++;
					inp[i + j ] = 'R';
				}
				if (!bl){
					b++;
					inp[i + j ] = 'B';
				}
				if (!yl){
					y++;
					inp[i + j ] = 'Y';
				}
				if (!gn){
					g++;
					inp[i + j ] = 'G';
				}
			}
		}
	}

	cout << r << " " << b << " " << y << " " << g;
	return 0;
}
