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

int main() {
	char path[] = { 'I', 'E', 'H', 'O', 'V', 'A' };
	int T;
	cin >> T;
	while (T--) {
		int m, n, x, y;
		cin >> m >> n;
		string ar[m];
		for (int i = 0; i < m; ++i) {
			cin >> ar[i];
			for (int j = 0; j < n; ++j) {
				if (ar[i][j] == '@')
					x = i, y = j;
			}
		}
		for (int i = 0; i < 6; ++i) {
			if (x - 1 > -1 && ar[x - 1][y] == path[i])
				cout << "forth ", x--;
			else if (y + 1 < n && ar[x][y + 1] == path[i])
				cout << "right ", y++;
			else if (y - 1 > -1 && ar[x][y - 1] == path[i])
				cout << "left ", y--;
		}
		if (x - 1 > -1 && ar[x - 1][y] == '#')
			cout << "forth", x--;
		else if (y + 1 < n && ar[x][y + 1] == '#')
			cout << "right", y++;
		else if (y - 1 > -1 && ar[x][y - 1] == '#')
			cout << "left", y--;
		cout << endl;
	}
	return 0;
}
