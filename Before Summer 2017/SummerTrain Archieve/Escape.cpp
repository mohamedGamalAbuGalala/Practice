//============================================================================
// Name        : Escape.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
int main() {
	double vp, vd, t, f, c;
	cin >> vp >> vd >> t >> f >> c;
	if (vp >= vd) {
		cout << 0 << endl;
		return 0;
	}
	int ans = 0;
	double begin = vp * t;
	while (1) {
		double T = begin * 1.0 / (vd - vp);
		begin += vp * T;
		if (begin - c >= 0)
			break;
		else {
			begin += (T + f) * vp;
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}
/*
 #include <iostream>
 using namespace std;

double vp, vd, t, f, c;

bool check(int bij) {
	double p = (t * vp);
//	, d = 0, dis = (vp / vd);
	do {
		double T = p * 1.0 / (vd - vp);
		p += (vp * T);
		if (p >= c)
			return 1;
		else
			p += (T + f) * vp;
//		d = 0;
//		while (d < p)
//			d += dis, p += dis;
//		p += (f + (p / vd)) * vp;
	} while (bij--);
	return p >= c;
}

int main() {
	cin >> vp >> vd >> t >> f >> c;
	if (vp >= vd) {
		int tmp = 0;
		cout << tmp << endl;
		return 0;
	}
	int s = 0, e = c, ret = 0;
	while (s < e) {
		int mid = (s + e) / 2;
		if (check(mid))
			e = mid - 1, ret = mid;
		else
			s = mid + 1;
	}
	cout << ret << endl;
	return 0;
}

*/
