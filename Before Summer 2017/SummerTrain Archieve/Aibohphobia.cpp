#include<stdio.h>
#include<algorithm>
#include<string>
using namespace std;

FILE * in = stdin;

int dp[6101][6101];
bool vis[6101][6101];
string t;

int solve(int s , int e)
{
    if(s >= e) return 0;
    if(vis[s][e]) return dp[s][e];
    vis[s][e] = 1;
    int ret = 1 << 30;
    if(t[s] == t[e]) ret = min(ret,solve(s+1,e-1));
    else
    {
        ret = min(ret,1+solve(s+1,e));
        ret = min(ret,1+solve(s,e-1));
    }
    return dp[s][e] = ret;
}

int main()
{
    int i , a , k;
    char x[6106];
    fscanf(in,"%d",&k);
    while(k--)
    {
        fscanf(in,"%s",x);
        t = x;
        printf("%d\n",solve(0,t.size()-1));
        memset(vis,0,sizeof vis);
    }
    return 0;
}
