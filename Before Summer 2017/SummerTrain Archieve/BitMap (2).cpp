#include<iostream>
#include<algorithm>
#include<string.h>
#include<queue>
using namespace std;

class node
{
	public:
	int x , y , d;
};

int n,m;
char grid[182][182];
queue<node> Q;
int dis[182][182];
int rx[] = {1,-1,0,0};
int ry[] = {0,0,1,-1};


int main()
{
	int i,j,cases;
	node cur;

	cin >> cases;
	while(cases--)
	{
		cin >> n >> m;
		for(i=0;i<n;i++)
			cin >> grid[i];
		
		for(i=0;i<n;i++)
			for(j=0;j<m;j++)
				if(grid[i][j] == '1')
				{
					cur.x = i;
					cur.y = j;
					cur.d = 0;
					Q.push(cur);
				}
		memset(dis,-1,sizeof dis);
		while(Q.size())
		{
			cur = Q.front();
			Q.pop();

			if(dis[cur.x][cur.y] != -1)
				continue;
			dis[cur.x][cur.y] = cur.d;

			for(i=0;i<4;i++)
			{
				node next;
				next.x = cur.x+rx[i];
				next.y = cur.y+ry[i];
				next.d = cur.d+1;
				
				if(next.x < 0 || next.x >= n || next.y < 0 || next.y >= m) continue;
				Q.push(next);
			}
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<m-1;j++)
				cout << dis[i][j] << " ";
			cout << dis[i][m-1] << endl;
		}
	}
}