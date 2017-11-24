// CasTle.cpp : Defines the entry point for the console application.
// by bu-galala
#include "stdafx.h"

/*
7 4
11 6 11 6 3 10 6
7 9 6 13 5 15 5
1 10 12 7 13 7 5
13 11 10 8 10 12 13
*/


#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;


int n, m, grid[50][50], vis[50][50], Size_[50 * 50], cnt = 0, maxR = 0;

void flood(int x, int y, int ind) {
	if (vis[x][y] != -1) return;
	vis[x][y] = ind;
	Size_[ind]++;
	if ((grid[x][y] & 1) == 0) flood(x, y - 1, ind);
	if ((grid[x][y] & 4) == 0) flood(x, y + 1, ind);
	if ((grid[x][y] & 8) == 0) flood(x + 1, y, ind);
	if ((grid[x][y] & 2) == 0) flood(x - 1, y, ind);
	return;
}


int main() {
	int i, j;
	cin >> m >> n;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			cin >> grid[i][j];
		}
	}
	memset(vis, -1, sizeof vis);
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			if (vis[i][j] == -1) {
				flood(i, j, cnt);
				maxR = max(maxR, Size_[cnt]);
				cnt++;
			}
		}
	}
	cout << cnt << endl;
	cout << maxR << endl;
	int maxO = 0, dx = 0, dy = 0;
	char d = ' ';
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (j < (m - 1) && vis[i][j] != vis[i][j + 1] && maxO< Size_[vis[i][j]] + Size_[vis[i][j + 1]]) {
				maxO = Size_[vis[i][j]] + Size_[vis[i][j + 1]];
				d = 'E'; dx = i + 1; dy = j + 1;
			}
			if (j > 0 && vis[i][j] != vis[i][j - 1] && maxO < Size_[vis[i][j]] + Size_[vis[i][j - 1]]) {
				maxO = Size_[vis[i][j]] + Size_[vis[i][j - 1]];
				d = 'W'; dx = i + 1; dy = j + 1;
			}
			if (i > 0 && vis[i][j] != vis[i - 1][j] && maxO < Size_[vis[i][j]] + Size_[vis[i - 1][j]]) {
				maxO = Size_[vis[i][j]] + Size_[vis[i - 1][j]];
				d = 'N'; dx = i + 1; dy = j + 1;
			}
			if (i < n - 1 && vis[i][j] != vis[i + 1][j] && maxO < Size_[vis[i][j]] + Size_[vis[i + 1][j]]) {
				maxO = Size_[vis[i][j]] + Size_[vis[i + 1][j]];
				d = 'S'; dx = i + 1; dy = j + 1;
			}
		}
	}
	cout << maxO << endl;
	cout << dx << "   " << dy << "   " << d << endl;
	return 0;
}

/*
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int grid [ 51 ] [ 51 ] , vis [ 51 ] [ 51 ] , n , m , cnt = 0 ;

int dir2 [ ] = { 0, -1, 0, 1 };
int dir [ ] = { -1, 0, 1, 0 };

void solve ( int i , int j , int val ) {
	//if ( i < 0 || i >= n || j < 0 || j >= n || vis [ i ] [ j ] != -1 )
	if ( i < 0 || i >= n || j < 0 || j >= m || vis [ i ] [ j ] != -1 )
		return ;
	vis [ i ] [ j ] = val ;
	for ( int l = 0 ; l < 4 ; l++ )
		if ( !( grid [ i ] [ j ] & ( 1 << l ) ) )
			solve ( i + dir2 [ l ] , j + dir [ l ] , val );
	return;
}

int main ( ) {
	int i , j ;
	memset ( vis , -1 , sizeof vis );
	scanf_s ( "%d%d" , &m , &n );
	for ( i = 0 ; i < n ; i++ )
		for ( j = 0 ; j < m ; j++ )
			scanf_s ( "%d" , &grid [ i ] [ j ] );

	for ( i = 0; i < n; i++ ) {
		for ( j = 0; j < m; j++ ) {
			if ( vis [ i ] [ j ] == -1 ) {
				solve(i, j,++cnt);
			}
		}
	}
	printf ( "%d\n" , cnt );
	return 0;
}
*/
