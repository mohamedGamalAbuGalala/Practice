/*
ID: hosam_s1
TASK: pprime
LANG: C++
*/
#include<stdio.h>
#include<algorithm>
#include<set>
using namespace std;

FILE * in = fopen("pprime.in","r");
FILE * out = fopen("pprime.out","w");

int s , e;
set<int> answer;

pair<int,int> calc(int cur)
{
    pair<int,int> ret;
    
    ret.first = ret.second = cur;
    
    ret.second *= 10;
    ret.second += cur % 10;
    cur /= 10;
    
    while(cur)
    {
        ret.first *= 10;
        ret.first += cur % 10;
        ret.second *= 10;
        ret.second += cur % 10;
        cur /= 10;
    }
    
    return ret;
}

bool isPrime(int num)
{
    for(int i=2;i*i <= num;i++)
        if(num % i == 0) return 0;
    return 1;
}

void solve(int cur)
{
    pair<int,int> pal = calc(cur);
    if(pal.first > e) return;
    if(pal.first >= s && pal.first <= e && isPrime(pal.first)) answer.insert(pal.first);
    if(pal.second >= s && pal.second <= e && isPrime(pal.second)) answer.insert(pal.second);
    
    for(int i=0;i<=9;i++)
    {
        if(!cur && !i) continue;
        solve(cur*10+i);
    }
    return;
}

int main()
{
    int i , j;
    
    fscanf(in,"%d %d",&s,&e);
    solve(0);
    
    while(answer.size())
    {
        fprintf(out,"%d\n",*answer.begin());
        answer.erase(answer.begin());
    }
    return 0;
}