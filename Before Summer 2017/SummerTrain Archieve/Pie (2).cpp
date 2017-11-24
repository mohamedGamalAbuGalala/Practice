#include<stdio.h>
#include<algorithm>
#include<math.h>
using namespace std;

int n , r[10001] , f , Max;
double vol[10001];

bool check(double v)
{
    int i , cnt = 0;
    for(i=0;i<n;i++)
        cnt += (int)(vol[i] / v);
    return cnt >= (f+1);
}

double binary_search()
{
    double s = 0 , e = vol[n-1];
    
    for(int i=0;i<100;i++)
    {
        double mid = (s + e) / 2.0;
        if(check(mid))
            s = mid;
        else
            e = mid;
    }
    return s;
}

int main()
{
    int i , a , cases;
    
    scanf("%d",&cases);
    while(cases--)
    {
        scanf("%d %d",&n,&f);
        for(i=0;i<n;i++)
        {
            scanf("%d",&r[i]);
            vol[i] = M_PI * r[i] * r[i]; //volume of each pie (height = 1)
        }
        sort(vol,vol+n);
        
        printf("%.4lf\n",binary_search());
    }
    return 0;
}