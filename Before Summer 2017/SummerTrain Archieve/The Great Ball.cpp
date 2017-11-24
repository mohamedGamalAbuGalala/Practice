#include<stdio.h>
#include<queue>
#include<algorithm>
using namespace std;
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
    scanf("%d",&k);
    while(k)
    {
        k--;
        scanf("%d",&n);
        for(i=0,c=0;i<n;i++)
        {
            scanf("%d %d",&a,&j);
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
