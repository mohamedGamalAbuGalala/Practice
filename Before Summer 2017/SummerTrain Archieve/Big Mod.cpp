#include<stdio.h>
#include<algorithm>
using namespace std;

int a , b , mod;

int bits[40] , cnt;

int main()
{
    long long ret;
    //freopen("in.in","r",stdin);
    
    while(scanf("%d %d %d",&a,&b,&mod) != EOF)
    {
        if(b == 0)
        {
            printf("1\n");
            continue;
        }
        
        a %= mod;
        cnt = 0;
        while(b)
        {
            bits[cnt++] = (b & 1);
            b /= 2;
        }
        ret = a;
        for(int i=cnt-2;i>-1;i--)
        {
            ret *= ret;
            if(bits[i]) ret *= a;
            ret %= mod;
        }
        printf("%lld\n",ret);
    }
}