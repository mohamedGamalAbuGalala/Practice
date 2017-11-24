//============================================================================
// Name        : HISTOGRAM.cpp
// Author      : Akram
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stack>
#include<vector>
#include <string.h>

using namespace std;
struct node {
	long long int value, index;
};

long long int n, arr[1000001], indR[1000001], indL[1000001];
stack<node> S;
vector<long long int> res;

int main() {
	cin >> n;
//	scanf("%d",n);
	while (n>0) {
		for (int i = 0; i < n && cin >> arr[i]; ++i);
		// for the minimum one from me
		for (int i = 0; i < n; ++i) {
			node cur;
			//condition
			while (S.size() && S.top().value >= arr[i])
				S.pop();
			if (!S.size())
				indL[i] = -1;
			else
				indL[i] = S.top().index;

			cur.value = arr[i];
			cur.index = i;
			S.push(cur);
		}
		//clear
		while (S.size())
			S.pop();
		for (int i = n - 1; i >= 0; --i) {
			node cur;
			while (S.size() && S.top().value >= arr[i])
				S.pop();
			if (!S.size())
				indR[i] = n - 1;
			else
				indR[i] = S.top().index;
			cur.value = arr[i];
			cur.index = i - 1;
			S.push(cur);
		}
		long long int ma = 0;
		for (int i = 0; i < n; ++i)
			ma = max(ma, ((indR[i] - indL[i]) * arr[i]));
		res.push_back(ma);
//		scanf("%d",n);
		cin >> n;
		//clear
		while (S.size())
			S.pop();
		memset(indL, 0, sizeof indL);
		memset(indR, 0, sizeof indR);
	}
	for (int i = 0; i < res.size() && cout << res[i] << endl; ++i);
	return 0;
}
/*  TestCases
7 2 1 4 5 1 3 3
4 1000 1000 1000 1000
4 8 1 2 3
0

 */
/*
		cout<< endl;
		for (int i = 0; i < n; ++i) {
			cout << indL[i] << " ";
		}
		cout << endl;
		for (int i = 0; i < n; ++i) {
			cout << indR[i] << " ";
		}*/
