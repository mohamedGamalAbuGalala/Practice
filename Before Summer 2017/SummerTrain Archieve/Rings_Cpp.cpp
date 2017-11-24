// database.cpp : Defines the entry point for the console application.
// by bu-galala
#include "stdafx.h"
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;
//int i[100];
pair<int, int> IC[100001];
bool res[100001];

//int I[10001];
//int C[1001];

bool cmp(pair<int, int> b, pair<int, int> a){
if (b.first < a.first) return 1;
if (b.first == a.first) return b.second < a.second;
return false;
}
int main() {
	int x, n, r, resind = 0, ind = 0;
	cin >> x;
	for (int i = 0; i < x; i++) {
		cin >> n >> r;
		for (int j = 0; j < r; j++) {
			cin >> IC[ind].first >> IC[ind].second;
			ind++;
		}
		int tmp = ind;
		ind -= r;
		res[resind] = true;
		bool wrong = false;
		sort(IC+ind, IC + tmp, cmp);
		for (int j = ind; !wrong && j < tmp -1; j++) {
			for (int k = j +1; k < tmp; k++) {
				if (IC[j].first == IC[k].first) {
					if (IC[j].second == IC[k].second) {
						res[resind] = false;
						wrong = true;
						break;
						//goto aa;
					}
				} else {
					break;
				}
			}
		}
		//aa:
		ind = tmp;
		resind++;
		cout << endl;
	}
	for (int i = 0; i < resind; i++) {
		string tmp = (res[i] == 1) ? "possible" : "Impossible";
		cout << "Scenario#" << i + 1 << ": " << tmp << endl;
	}
	return 0;
}

#pragma region Maze

//int n = 5;
//char maze[5][5];
//bool vis[5][5];
//
//
//
//bool find(int i, int j) {
//	if (i >= n || j >= n || i < 0 || j < 0 || maze[i][j] == 'x' || vis[i][j] == 1)
//		return 0;
//	else if (maze[i][j] == 'E')
//		return 1;
//	vis[i][j] = 1;
//	if (find(i, j + 1))return true;//right
//	if (find(i, j - 1))return true;//left
//	if (find(i + 1, j))return true;//bottom
//	if (find(i - 1, j))return true;//top
//	vis[i][j] = 0;
//	return 0;
//}
//
//int main() {
//	cout << "hello" << endl;
//	int id, ij;
//	for (int i = 0; i < 5; ++i) {
//		for (int j = 0; j < 5; ++j) {
//			cin >> maze[i][j];
//		}
//	}
//	for (int i = 0; i < 5; ++i) {
//		for (int j = 0; j < 5; ++j) {
//			if (maze[i][j] == 'S') {
//				id = i;
//				ij = j;
//			}
//		}
//	}
//	bool res = find(id, ij, 0);
//	cout << res << endl;
//
//	return 0;
//}

#pragma endregion

#pragma region rings

//
//int _tmain(int argc, _TCHAR* argv[])
//{
//	//for (int i = 0; i <= 5; i++) {
//	//	register int n = 7;
//	//	printf("%d \n", n++);
//	//}
//
//	//for (int i = 0; i <= 5; i++) {
//	//	static int n = 7;
//	//	printf("%d \n", n++);
//	//}
//
//
//
//
//
//
//	//string inputString;
//	//cout << "Type a String : ";
//	//getline(cin, inputString);
//	//////	cin>> inputString;
//	//cout << "Input is : " << inputString << endl;
//
//	return 0;
//}

#pragma endregion



