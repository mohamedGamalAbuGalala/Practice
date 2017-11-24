/*
//============================================================================
// Name        : Maze.cpp
// Author      : Akram
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
char arr[1000][1000];
int n;
bool solve(int i, int j, int d) {
	if (i >= n || i < 0 || j >= n || j < 0 || arr[i][j] == 'x')
		return false;
	else if (arr[i][j] == 'e')
		return true;
	else {
		if (d == 1) {
			return (solve(i, j + 1, 1) || solve(i + 1, j, 4)
					|| solve(i - 1, j, 3));
		}
		else if (d == 2) {
			return (solve(i, j - 1, 2) || solve(i + 1, j, 4)
					|| solve(i - 1, j, 3));
		}
		else if (d == 3) {
			return (solve(i, j + 1, 1) || solve(i, j - 1, 2)
					|| solve(i - 1, j, 3));
		}
		else if (d == 4) {
			return (solve(i, j + 1, 1) || solve(i + 1, j, 4)
					|| solve(i - 1, j, 3));
		}
		else{
			return (solve(i, j + 1, 1)||solve(j , j-1 , 2) || solve(i + 1, j, 4)
								|| solve(i - 1, j, 3));
		}
	}

}
int main() {
	cin >> n;
	for (int i = 0; i < n ; i++){
		for (int j = 0; j < n; j++)
			cin >> arr[i][j] ;
		cout<< endl;
	}
	bool res = solve(0, 0, 0);
	cout << res << endl;
	return 0;
}
*/
