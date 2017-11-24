#include<stdio.h>
#include<algorithm>
#include<string>
using namespace std;

FILE * in = stdin;

int dp[2001][2001];
bool flag[2001][2001];
string s , t;

int solve(int ind , int ind1)
{
    if(ind == s.size() && ind1 == t.size()) return 0;
    if(flag[ind][ind1]) return dp[ind][ind1];
    flag[ind][ind1] = 1;
    int ret = 1 << 30;
    if(s[ind] == t[ind1]) return dp[ind][ind1] = solve(ind+1,ind1+1);
    if(ind < s.size()) ret = min(ret ,1 + solve(ind+1,ind1));
    if(ind1 < t.size()) ret = min(ret ,1 + solve(ind,ind1+1));
    if(ind < s.size() && ind1 < t.size()) ret = min(ret ,1 + solve(ind+1,ind1+1));
    return dp[ind][ind1] = ret;
}

int main()
{
    int i , a , k;
    char x[3000];
    fscanf(in,"%d",&k);
    while(k--)
    {
        fscanf(in,"%s",x); t = x;
        fscanf(in,"%s",x); s = x;
        printf("%d\n",solve(0,0));
        memset(flag,0,sizeof flag);
    }
    return 0;
}
