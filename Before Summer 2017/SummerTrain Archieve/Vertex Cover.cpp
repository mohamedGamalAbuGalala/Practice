#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
using namespace std;

int n;
vector<int> arr[100001];
int memo[100001][2];

int solve(int node, bool flag, int parent)
{
	if(arr[node].size() == 1 && arr[node][0] == parent)
		return (!flag);
	if(memo[node][flag] != -1) return memo[node][flag];
	
	int ret1 = 1 , ret2 = 0;
	for(int i=0;i<arr[node].size();i++)
	{
		if(arr[node][i] == parent) continue;
		ret1 += solve(arr[node][i],1,node);
 		if(flag)
			ret2 += solve(arr[node][i],0,node);
	}
	if(flag) ret1 = min(ret1,ret2);
	return memo[node][flag] = ret1;
}

int main()
{
	int i , s , e;

	cin >> n;
	for(i=0;i<n-1;i++)
	{
		cin >> s >> e;
		
		arr[s].push_back(e);
		arr[e].push_back(s);
	}
	
	memset(memo,-1,sizeof memo);
	cout << solve(1,1,0);
}