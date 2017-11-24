#include <iostream>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <algorithm>
#include <string.h>
#include <array>
#include <iterator>
#include <set>
#include <cmath>
#include<iomanip>	// Stew(10)		::        12	........ 8 spaces and 2 digits in 10 padding right

#define pb push_back
#define up upper_bound
#define lp lower_bound
#define pr pair<int,int>
#define ll long long int

using namespace std;

int T, n;
char ar[101][101];

void dfs(int i, int j) {
	if (i < 0 || j < 0 || i >= n || j >= n)
		return;
	if (ar[i][j] == '.')
		return;
	ar[i][j] = '.';
	dfs(i + 1, j), dfs(i - 1, j), dfs(i, j + 1), dfs(i, j - 1);
}

int main() {
	int cases = 0;
	cin >> T;
	while (T--) {
		int res = 0;
		cin >> n;
		for (int i = 0; i < n && cin >> ar[i]; ++i)
			;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				if (ar[i][j] == 'x')
					res++, dfs(i, j);
		cout<<"Case "<<++cases<<": "<<res<<endl;
	}

	return 0;
}
