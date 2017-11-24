#include "stdafx.h"
// 36. Equidivisions.cpp : Defines the entry point for the console application.
//  :: by bu_galala
#include <string>
#include <sstream>
#include <iostream>
#include "memory.h"

using namespace std;

int M[100][100];
bool visited[100][100];
int n;
int vi[] = { -1, 1, 0, 0 };
int vj[] = { 0, 0, 1, -1 };

int dfs(int a, int b)
{
	visited[a][b] = 1;

	int I, J;
	int cont = 1;

	for (int i = 0; i < 4; i++)
	{
		I = a + vi[i];
		J = b + vj[i];

		if (!(I >= 0 && J >= 0 && I < n && J < n)) continue;
		if (M[a][b] == M[I][J] && !visited[I][J]) cont += dfs(I, J);

	}

	return cont;
}

int main()
{

	bool ok;

	while (cin >> n)
	{
		if (n == 0) break;

		string aux;
		getline(cin, aux);

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				M[i][j] = n;

		for (int i = 1; i < n; i++)
		{
			string s;
			getline(cin, s);
			stringstream is(s);
			int x, y;
			while (is >> x >> y)
			{
				M[x - 1][y - 1] = i;
			}
		}

		memset(visited, 0, sizeof(visited));

		ok = true;

		for (int i = 0; i < n && ok; i++)
		{
			for (int j = 0; j < n && ok; j++)
			{
				if (!visited[i][j])
				{
					if (dfs(i, j) != n)
						ok = false;
				}
			}
		}

		if (ok) cout << "good" << endl;
		else cout << "wrong" << endl;

	}

	return 0;
}
/*
#include <iostream>
#include <string.h>
using namespace std;
int arr[1001][1001], vis[1001][1001], n;

void solve(int x, int y) {
	if (x == n || y == n || x < 0 || y < 0)	return;
	if (vis[x][y] != 0) return;
	vis[x][y] = 1;
	bool flag = 1;
	if (arr[x][y + 1] == arr[x][y]) { flag = 0 ; solve(x, y + 1);}
	if (arr[x + 1][y] == arr[x][y]) { flag = 0 ; solve(x + 1, y);}
	if (arr[x][y - 1] == arr[x][y]) { flag = 0 ; solve(x, y - 1);}
	if (arr[x - 1][y] == arr[x][y]) { flag = 0 ; solve(x - 1, y);}
	if(flag) vis[x][y] = 0;
	return;
}

int main() {
	bool res[1001];
	int cnt = 0;
	//cin >> n;
	scanf_s("%d", &n);
	do {
		for (int i = 1; i <= (n - 1); i++) {
			int x, y;
			for (int j = 0; j < n; j++) {
				//cin >> x >> y;
				scanf_s("%d %d", &x,&y);
				arr[x - 1][y - 1] = i;
			}
			solve(x - 1, y - 1);
		}
		res[cnt] = 1;
		bool wrong = 0, flag = 1;
		for (int i = 0; i < n && !wrong; i++) {
			for (int j = 0; j < n; j++) {
				if (flag && arr[i][j] == 0) {
					solve(i, j);
					flag = 0;
				}
				if (vis[i][j] == 0) {
					res[cnt] = 0;
					wrong = 1;
					break;
				}
			}
		}
		cnt++;
		scanf_s("%d", &n);
		memset(vis, 0, sizeof vis);
		memset(arr, 0, sizeof arr);
	} while (n > 0);
	for (int i = 0; i < cnt; i++) {
		if (res[i])
			cout << "good" << endl;
		else
			cout << "wrong" << endl;
	}
	return 0;
}
*/
/*
5
1 1 1 2 1 3 3 2 2 2
2 1 4 2 4 1 5 1 3 1
4 5 5 2 5 3 5 5 5 4
2 5 3 4 3 5 4 3 4 4
2
1 2 2 1
5
1 1 1 2 1 3 3 2 2 2
2 1 3 1 4 1 5 1 4 2
4 5 5 2 5 3 5 5 5 4
2 4 1 4 4 3 4 4 3 5
0
>> good
>> wrong
>> wrong
*/
/*for (int i = 0; i < n && !wrong; i++) {
	for (int j = 0; j < n; j++) {
	// top
	if (i>0 && arr[i][j] == arr[i - 1][j])
	vis[i][j] = 1;
	// bottom
	else if (i<n - 1 && arr[i][j] == arr[i + 1][j])
	vis[i][j] = 1;
	// left
	else if (j>0 && arr[i][j] == arr[i][j - 1])
	vis[i][j] = 1;
	// right
	else if (j < n - 1 && arr[i][j] == arr[i][j + 1])
	vis[i][j] = 1;
	else {
	vis[i][j] = -1;
	wrong = 1;
	res[cnt] = 0;
	break;
	}
	}
	}
	*/

/*
#pragma region logic
for (int i = 0; i < n && !wrong; i++) {
for (int j = 0; j < n; j++) {
if (vis[i][j] == -1) {
solve(i, j, arr[i][j]);
if (vis[i][j] == -1) {
res[cnt] = 0;
wrong = 1;
break;
}
}
}
}
#pragma endregion
*/


/*
bool solve(int x, int y, int id) {
bool r = 0;
if (x == n || y == n || x < 0 || y < 0 || arr[x][y] != id)	return 0;
if (vis[x][y] == 1) return 1;
vis[x][y] = 1;
if (solve(x, y + 1, id)) { r = 1; return 1; }
if (solve(x, y - 1, id)) { r = 1; return 1; }
if (solve(x + 1, y, id)) { r = 1; return 1; }
if (solve(x - 1, y, id)) { r = 1; return 1; }
if (r == 0)
vis[x][y] = -1;
return 0;
}
*/