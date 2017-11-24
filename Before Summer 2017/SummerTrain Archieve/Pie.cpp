/*#include <bits/stdc++.h>
 using namespace std;
 int n, f;
 long double pi = 3.14159265358979323846264338327950;
 int func(long double num, long double array[]) {
 int fr = 0;
 if (num == 0)
 return 0;
 for (int i = 0; i < n; i++)
 fr += (int) (array[i] / num);
 if (fr >= f)
 return 1;
 else
 return 0;
 }
 long double bs(long double array[]) {
 long double ini = 0, last = array[n - 1];
 while (last - ini >= 1e-6) {
 //printf("%.2Lf %.2Lf\n",ini,last);
 long double mid = (ini + last) / 2;
 if (func(mid, array) == 1) {
 ini = mid;
 } else
 last = mid;
 }
 return ini;
 }
 int main() {
 int t;
 scanf("%d", &t);
 while (t--) {
 scanf("%d %d", &n, &f);
 f++;
 int array1[n];
 for (int i = 0; i < n; i++)
 scanf("%d", &array1[i]);
 long double array[n];
 sort(array1, array1 + n);
 for (int i = 0; i < n; i++)
 array[i] = array1[i] * array1[i] * pi;
 long double k = bs(array);
 printf("%.4Lf\n", k);
 }
 return 0;
 }*/

//============================================================================
// Name        : Pie.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
 #include <iostream>
 #include <iomanip>
 #include <algorithm>
 #include <math.h>

//#include <bits/stdc++.h>
using namespace std;

//#define V(r) (3.14159265358979323846264338327950L * r * r)
int n, f, pie[10001];
long double pi = 3.14159265358979323846264338327950;
long double V(int r) {
	return pi * r * r;
}
bool check(long double vol) {
	if (vol == 0)
		return 0;
	int i, cnt = 0;
	for (i = 0; i < n; ++i) {
		long double cur = V(pie[i]);
		cnt += (int) (cur / vol);
	}
	return cnt >= f;
}

int main() {
	int t, i;
	cin >> t;
	while (t--) {
		cin >> n >> f;
		f++;
		for (i = 0; i < n && cin >> pie[i]; ++i)
			;
		sort(pie, pie + n);
		long double s = 0, e = V(pie[n - 1]), ret;
		while ((e - s) >= 1e-6) {
			long double mid = (s + e) / 2;
			if (check(mid)) {
				s = mid, ret = mid;
			} else
				e = mid;
		}
		cout << fixed;
		cout << setprecision(4);
		cout << ret << endl;
	}
	return 0;
}

