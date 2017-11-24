//============================================================================
// Name        : Maze.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
int n = 5;
char maze[5][5];
bool vis[5][5];

bool find(int i, int j) {
	if (i >= n || j >= n || i < 0 || j < 0 || maze[i][j] == 'x' || vis[i][j] ==  1)
		return 0;
	else if (maze[i][j] == 'E')
		return 1;
	vis[i][j] = 1;
	if (find(i, j + 1))return true;//right
	if (find(i, j - 1))return true;//left
	if (find(i + 1, j))return true;//bottom
	if (find(i - 1, j))return true;//top
	vis[i][j] = 0;
	return 0;
}

int main() {
	cout << "hello" << endl;
	int id, ij;
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			cin >> maze[i][j];
		}
	}
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			if (maze[i][j] == 'S') {
				id = i;
				ij = j;
			}
		}
	}
	bool res = find(id, ij);
	cout << res << endl;

	return 0;
}
