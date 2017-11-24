#include<algorithm>
#include<stdio.h>
using namespace std;
long long m;
long long t[10000001];
long long solve(long long k)
{
    if(k <= 10000000) if(t[k]) return t[k];
    if(k == 0) return 0;
    return (long long) max(solve(k/2)+solve(k/3)+solve(k/4),k);
}
int main()
{
    long long i,a;
    for(i=0;i<10000000;i++)
        t[i] = solve(i);
    while(scanf("%d",&m) != EOF)
        printf("%lld\n",solve(m));
    return 0;
}
