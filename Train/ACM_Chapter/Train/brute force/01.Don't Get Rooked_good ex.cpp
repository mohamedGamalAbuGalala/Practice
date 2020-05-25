#include<stdio.h>
#include<algorithm>
using namespace std;

int n;
char arr[5][5];

bool safe(int x, int y) {
	for (int i = x; i > -1 && arr[i][y] != 'X'; i--) //checking upper part
		if (arr[i][y] == 'R')
			return 0;
	for (int i = y; i > -1 && arr[x][i] != 'X'; i--) //checking left part
		if (arr[x][i] == 'R')
			return 0;
	return 1;
}

long long int cnt = 0;

int solve(int x, int y) {
//	cnt++;
	if (y == n)
		return solve(x + 1, 0);
	if (x == n)
		return 0;

	int ret = 0;
	if (arr[x][y] == '.' and safe(x, y)) {
		arr[x][y] = 'R';
		ret = 1 + solve(x, y + 1);
		arr[x][y] = '.';
	}
	ret = max(ret, solve(x, y + 1));
	return ret;
}

int main() {
	int i;
	while (scanf("%d", &n) && n) {
		for (i = 0; i < n; i++)
			scanf("%s", arr[i]);
		printf("%d\n", solve(0, 0));
	}
	return 0;
}
