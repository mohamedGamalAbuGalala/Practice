#include<stdio.h>
#include<vector>
using namespace std;
int main()
{
    int  i , a , b , k;
    int t[10][6] =  {{0},{1},{2,4,8,6},{3,9,7,1},{4,6},{5},{6},{7,9,3,1},{8,4,2,6},{9,1}};
    int c[] = {1,1,4,4,2,1,1,4,4,2};
    scanf("%d",&k);
    for(i=0;i<k;i++)
    {
        scanf("%d %d",&a,&b);
        if(b == 0) printf("1\n");
        else
        {
            b--; a%=10; b%=c[a];
            printf("%d\n",t[a][b]);
        }
    }
    return 0;
}
