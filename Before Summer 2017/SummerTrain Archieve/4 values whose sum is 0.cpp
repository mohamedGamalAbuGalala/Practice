#include<algorithm>
#include<stdio.h>
using namespace std;
int A[4001] , B[4001] , C[4001] , D[4001] , n , t[16000001];
int main()
{
    int i , a , cur = 0;
    long long ret = 0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d %d %d %d",&A[i],&B[i],&C[i],&D[i]);
    for(i=0;i<n;i++)
        for(a=0;a<n;a++)
            t[cur++] = A[i] + B[a];
    sort(t,t+cur);
    for(i=0;i<n;i++)
        for(a=0;a<n;a++)
            ret += (upper_bound(t,t+cur,(C[i] + D[a])*-1)-t) - (lower_bound(t,t+cur,(C[i] + D[a])*-1)-t);
    printf("%lld\n",ret);
    return 0;
}
