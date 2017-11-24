// ABSDEF.cpp : by bu-galala
#include "stdafx.h"
#include <iostream>
#include <algorithm>
using namespace std;
/*
1 1 >> 1
2 2 3 >> 4
2 -1 1 >> 24
3 5 7 10 >> 10
2 1 0 >> 12
2 0 1 >> 12
3 0 1 0 >> 105
3 1 0 1 >> 186
*/
int L[1000001], R[1000001], n, arr[101], cntR = 0, cntL = 0, ar[3], ans = 0;
#define LH(a , b , c) ((a*b)+c)
#define RH(d , e , fe) ((fe+e)*d)
void solve(int in) {
	if (in == 3) {
		L[cntL++] = LH(ar[0], ar[1], ar[2]);
		if (ar[0] == 0)
			return;
		R[cntR++] = RH(ar[0], ar[1], ar[2]);
	} else {
		for (int i = 0; i < n; i++) {
			ar[in] = arr[i];
			solve(in + 1);
		}
	}
}
int main(void) {
	cin >> n;
	for (int i = 0; i < n && cin >> arr[i]; i++);
	solve(0);
	sort(L, L + cntL);
	for (int i = 0; i < cntR; i++)
		ans +=(upper_bound(L, L + cntL, R[i]) - lower_bound(L, L + cntL, R[i]));
	cout << ans << endl;	return 0;
}

//int[] sol(int i) {
//
//}
//int[] com() {
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			for (int k = 0; k < n; k++) {
//
//			}
//		}
//	}
//}
//
//void solve(/*int i*/) {
//	//if (cnt >= pow(n, 3)) return;
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			for (int k = 0; k < n; k++) {
//
//				int l = LH(arr[i], arr[j], arr[k]);
//				int r = RH(arr[i], arr[j], arr[k]);
//				L[cnt] = l;
//				R[cnt] = r;
//				cnt++;
//			}
//		}
//	}
//
//	//cnt++;
//}
//
//if (binary_search(R[i],s,e)) {
//int s = 0, e = cnt - 1;

bool binary_search(int key, int start, int end) {
	if (start > end) {
		return false;
	}
	int middle = (start + end) / 2;
	if (key == L[middle]) {
		return true;
	} else if (key <= L[middle]) {
		return binary_search(key, start, middle - 1);
	} else {
		return binary_search(key, middle + 1, end);
	}
}

