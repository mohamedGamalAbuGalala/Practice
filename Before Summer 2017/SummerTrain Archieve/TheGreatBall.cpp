// TheGreatBall.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include<stdio.h>
//#include<queue>
#include<algorithm>
using namespace std;

class node {
public:
	int n , f;
};

bool cmp ( int b , int a ) {
	return a > b;
}

int main ( ) {

	return 0;
}















/*
class node
{
public :
	int n , f;
};
node t[201];
bool cmp(node a , node b)
{
	return a.n < b.n;
}
int main()
{
	int i , a , k , j , ret , n , c;
	scanf_s("%d",&k);
	while(k)
	{
		k--;
		scanf_s("%d",&n);
		for(i=0,c=0;i<n;i++)
		{
			scanf_s("%d %d",&a,&j);
			t[c].n = a; t[c++].f = 0;
			t[c].n = j; t[c++].f = 1;
		}
		sort(t,t+c,cmp);
		ret = 0 , j = 0;
		for(i=0;i<c;i++)
		{
			if(t[i].f) j--;
			else j++;
			ret = max(ret,j);
		}
		printf("%d\n",ret);
	}
	return 0;
}
*/
/*
#include <iostream>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

int arr[100000][2], n, tree[250000];
set<int> S;
map<int, int> Rank;

void update(int node, int s, int e, int x, int y) {
	if (s > y || e < x) return;
	if (s >= x && e <= y) {
		tree[node]++;
		return;
	}
	int mid = (s + e) / 2;
	update(node * 2, s, mid, x, y);
	update((node * 2) + 1, mid + 1, e, x, y);
	return;
}

int solve(int node, int s, int e, int ind) {
	if (ind > e, ind < s) return 0;
	if (s == e) {
		if (s == ind)	return tree[node];
		return 0;
	}
	int ret = tree[node], mid = (s + e) / 2;
	ret += solve(node * 2, s, mid, ind);
	ret += solve((node * 2) + 1, mid + 1, e, ind);
	return ret;
}
/*
5
1 7
2 4
6 9
3 8
5 10

int main() {
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf_s("%d %d", &arr[i][0], &arr[i][1]);
		S.insert(arr[i][0]);
		S.insert(arr[i][1]);
	}
	int cur = 0, cnt = 0;
	while (S.size()) {
		cur = *S.begin();
		S.erase(*S.begin());
		Rank[cur] = cnt++;
	}
	for (int i = 0; i < n; i++) {
		arr[i][0] = Rank[arr[i][0]];
		arr[i][1] = Rank[arr[i][1]];
	}
	for (int i = 0; i < n; i++) {
		update(1, 0, cnt - 1, arr[i][0], arr[i][1]);
	}
	int ret = 0;
	for (int i = 0; i < cnt; i++) {
		ret = max(ret, solve(1, 0, cnt - 1, i));
	}
	printf("%d", ret);
	return 0;
}

*/