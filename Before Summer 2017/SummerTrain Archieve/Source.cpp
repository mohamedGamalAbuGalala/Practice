
#include "stdafx.h"
//// 6.Sort Sort And Sort.cpp : Defines the entry point for the console application.
////
//
//#include "stdafx.h"
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