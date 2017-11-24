#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
vector<int> arr[100];
int ret1, ret2;
int solve(int cur){
	if (!arr[cur].size())return 0;
	ret1 = 0;
	for (int i = 0; i < arr[cur].size(); i++){
		ret1 = solve(arr[cur][i]) + 1;
		ret2 = max(ret1, ret2);
	}
	return ret2;
}
int main(){
	int n, x, y;
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> x >> y;
		arr[y].push_back(x);
	}
	int res = solve(0);
	cout << res<<endl;
	return 0;
}