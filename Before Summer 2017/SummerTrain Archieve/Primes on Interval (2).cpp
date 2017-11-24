#include<stdio.h>
#include<algorithm>
using namespace std;

int a , b , k;
bool vis[1000001];
int sum[1000001];

void seive()
{
    int i , j;
    for(i=2;i<=b;i++)
        if(!vis[i])
            for(j=i+i;j<=b;j+=i)
                vis[j] = 1;
    
    for(i=2;i<=b;i++)
        sum[i] = sum[i-1] + (!vis[i]);
    return;
}

bool check(int l)
{
    int i;
    for(i=a ;i+l <= b+1;i++)
        if(sum[i+l-1] - sum[i-1] < k) return 0;
    return 1;
}

int binary_search()
{
    int s = 0, e = b-a+1, ret=-1;
    check(2);
    while(s <= e)
    {
        int mid = (s + e)/2;
        if(check(mid))
            e = mid - 1 , ret = mid;
        else
            s = mid + 1;
    }
    return ret;
}

int main()
{
    int i , j , s , e , ret;
    
    scanf("%d %d %d",&a,&b,&k);
    seive();
    printf("%d\n",binary_search());
    
    return 0;
}
