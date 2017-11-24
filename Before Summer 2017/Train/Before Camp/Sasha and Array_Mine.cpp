//============================================================================
// Name        : Sasha.cpp
// Author      : abu-galala
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string.h>
#include <vector>

using namespace std;


#define lli long long int


lli _size, n_op;


lli _max = 1000000007;
lli memo[1000000];

vector<lli> arr;

lli fib(lli ind) {
	if (memo[ind] != -1)
		return memo[ind];
	if (ind == 1 || ind == 2)
		return 1;
	else
		return memo[ind] = fib(ind - 1) + fib(ind - 2);
}

lli fib_sum(lli s, lli e) {
	lli ret = 0;
	for (lli i = s - 1; i < e; ++i)
		ret += fib(arr[i]);
	return ret;
}

void sum(lli s,lli e, lli val) {
	for (lli i = s - 1; i < e; ++i)
		arr[i] += val;
}

int main() {
	lli optype, s, e, val, i;
	memset(memo, -1, sizeof memo);
	cin>>_size>>n_op;
	for (i = 0; i < _size; ++i) {
		lli tmp;
		cin>>tmp;
		arr.push_back(tmp);
	}

	for (i = 0; i < n_op; ++i) {
		cin>>optype>>s>>e;
		if (optype == 1) {
			cin>>val;
			sum(s, e, val);
		} else if (optype == 2) {
			lli res = fib_sum(s, e) % _max;
			cout<<res<<endl;
		}
	}
	return 0;
}
