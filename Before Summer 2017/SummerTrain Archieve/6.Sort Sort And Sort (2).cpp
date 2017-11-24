// 6.Sort Sort And Sort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
//============================================================================
// Name        : Sort.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <algorithm>
using namespace std;

pair<int, int> arr[10001];

bool even(int x) {
	if (x < 0)
		x *= -1;
	if (x % 2 == 0)
		return 1;
	return 0;
}
bool odd(int x) {
	if (x < 0)
		x *= -1;
	if (x % 2)
		return 1;
	return 0;
}
bool cmp(pair<int, int> b, pair<int, int> a) {
	if (a.second > b.second)
		return 1;
	if (a.second == b.second) {
		if (odd(b.first) && even(a.first))
			return 1;
		if (odd(b.first) && odd(a.first))
			return a < b;
		if (even(b.first) && even(a.first))
			return a > b;
	}
	return 0;
}

int main() {
	int n, m, i;
	while (scanf_s("%d %d", &n, &m)) {
		if (n == 0 && m == 0) {
			printf("0 0\n");
			break;
		}
		printf("%d %d\n", n, m);
		for (i = 0; i < n; ++i) {
			scanf_s("%d\n", &arr[i].first);
			arr[i].second = arr[i].first % m;
		}
		sort(arr, arr + n, cmp);
		for (i = 0; i < n; ++i) {
			printf("%d\n", arr[i].first);
		}
	}
	return 0;
}

//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
//struct input {
//	int num;
//	int mod;
//} a [10001];
//
//int n;
//int m;
//
//bool odd (int x)
//{
//	if ( x < 0 ) x *= -1;
//	if ( x % 2 ) return true;
//	return false;
//}
//
//bool even (int x)
//{
//	if ( x < 0 ) x *= -1;
//	if ( x % 2 == 0 ) return true;
//	return false;
//}
//
//bool operator< (input a, input b)
//{
//	if ( a.mod < b.mod ) return true;
//
//	if ( a.mod == b.mod ) {
//		if ( odd (a.num) && even (b.num) ) return true;
//		if ( odd (a.num) && odd (b.num)  ) return a.num > b.num;
//		if ( even (a.num) && even (b.num) ) return a.num < b.num ;
//	}
//
//	return false;
//}
//
//int main ()
//{
//	while ( scanf_s ("%d %d", &n, &m) ) {
//
//		if ( n == 0 && m == 0 ) {
//			printf ("0 0\n");
//			break;
//		}
//
//		printf ("%d %d\n", n, m);
//
//		for ( int i = 0; i < n; i++ ) {
//			scanf_s ("%d", &a [i].num);
//			a [i].mod = a [i].num % m;
//		}
//
//		sort (a, a + n);
//
//		for ( int i = 0; i < n; i++ )
//			printf ("%d\n", a [i].num);
//
//	}
//
//	return 0;
//}