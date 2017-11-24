//============================================================================
// Name        : Don't.cpp
// Author      : BuGalala
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
#define pb push_back

char arr[4][4];

bool safe(int x, int y) {
	int i;
	for (i = 0; x + i < 4; ++i) {
		if (arr[x + i][y] == 'X')
			break;
		if (arr[x + i][y] == 'R')
			return 0;
	}
	for (i = 0; y + i < 4; ++i) {
		if (arr[x][y + i] == 'X')
			break;
		if (arr[x][y + i] == 'R')
			return 0;
	}
	for (i = 0; x - i > -1; ++i) {
		if (arr[x - i][y] == 'X')
			break;
		if (arr[x - i][y] == 'R')
			return 0;
	}
	for (i = 0; y - i > -1; ++i) {
		if (arr[x][y - i] == 'X')
			break;
		if (arr[x][y - i] == 'R')
			return 0;
	}
	return 1;
}

int solve(int x, int y) {
	if (y > 3)
		return solve(x + 1, 0);
	if (x > 3)
		return 0;
	int ret1 = 0, ret2 = 0;
	if (arr[x][y] == '.' && safe(x, y)) {
		arr[x][y] = 'R';
		ret1 = 1 + solve(x, y + 1);
		arr[x][y] = '.';
	}
	ret2 = solve(x, y + 1);
	return max(ret1, ret2);
}

int main() {
	vector<int> res;
	int s, i, j;
	while (scanf("%d", &s) && s != 0) {
		memset(arr, '\0', sizeof arr);
		for (i = 0; i < s; ++i) {
			scanf("\n");
			for (j = 0; j < s; ++j)
				scanf("%c", &arr[i][j]);
		}
		scanf("\n");
		res.pb(solve(0, 0));
	}
	for (i = 0; i < res.size(); ++i)
		printf("%d\n", res[i]);
	return 0;
}

/*
4
.X..
....
XX..
....
2
XX
.X
3
.X.
X.X
.X.
3
...
.XX
.XX
4
....
....
....
....
0
>>>
5
1
5
2
4
 */
