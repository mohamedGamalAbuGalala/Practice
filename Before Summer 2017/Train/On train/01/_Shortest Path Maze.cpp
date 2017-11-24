#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n, m, vis[101][101] , depth[101][101];
char arr[101][101];
bool valid(int i , int j){
	return i>= 0 && i < n && j >= 0 && j < n && arr[i][j] == '.';
}
int di[]= {1 , -1 , 0 , 0};
int dj[] = {0 , 0 , 1 , -1};
int main() {
	int si  , sj , ei , ej;
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		scanf("%s", arr[i]);

	cin >> si >> sj >> ei >> ej;
	queue< pair<int , int> > q;
	q.push(make_pair(si , sj));
	vis[si][sj] = 1;
	depth[si][sj] = 0;
	while(q.size()){
		int i = q.front().first , j = q.front().second;
		q.pop();
		if(i == ei && j == ej){
			cout << depth[i][j];
			return 0 ;
		}
		for (int z = 0; z < 4; ++z) {
			int ti = i + di[z];
			int tj = j + dj[z];
			if(valid(ti , tj) && !vis[ti][tj] ){
				depth[ti][tj] = depth[i][j]  +1 ;
				q.push(make_pair(ti , tj));
			}
		}
	}

	return 0;
}

// BFS (Breadth First Search)
/*
 * 		traverse level by level
 */
