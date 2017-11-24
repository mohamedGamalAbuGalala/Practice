//============================================================================
// Name        : celender.cpp
// Author      : abu-galala
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	int m, d, res = 5;
	cin >> m >> d;

	if (m == 1 && d > 5)			//1		31		5
		res = 6;
	else if (m == 2 && d < 2)		//2		28		2
		res = 4;
	else if (m == 3 && d > 5)		//3		31		5
		res = 6;
	else if (m == 4 && d > 6)		//4		30		6
		res = 6;
	else if (m == 5 && d > 5)		//5		31		5
		res = 6;
	else if (m == 6 && d > 6)		//6		30		6
		res = 6;
	else if (m == 7 && d > 5)		//7		31		5
		res = 6;
	else if (m == 8 && d > 5)		//8		31		5
		res = 6;
	else if (m == 9 && d > 6)		//9		30		6
		res = 6;
	else if (m == 10 && d > 5)		//10	31		5
		res = 6;
	else if (m == 11 && d > 6)		//11	30		6
		res = 6;
	else if (m == 12 && d > 5)		//12	31		5
		res = 6;

	cout << res<<endl;
	return 0;
}
