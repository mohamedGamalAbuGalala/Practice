#include<stdio.h>
#include<algorithm>
#include<math.h>
using namespace std;

int n;
pair<int,int> arr[8];

bool check(int gap)
{
    int i , pre = arr[0].first;
    for(i=1;i<n;i++)
    {
        if(pre+gap <= arr[i].first)
            pre = arr[i].first;
        else if(pre+gap > arr[i].first && pre+gap <= arr[i].second)
            pre += gap;
        else
            return 0;
    }
    return 1;
}

int binary_search()
{
    int s = 0 , e = 1440 * 60000 , ret;

    while(s <= e)
    {
        int mid = (s + e) / 2;
        if(check(mid))
            s = mid + 1 , ret = mid;
        else
            e = mid - 1;
    }
    return ret;
}

int main()
{
    int i , a , ans , caseID = 0;
    int s , e;

    while(scanf("%d",&n) && n)
    {
        for(i=0;i<n;i++)
        {
            scanf("%d %d",&arr[i].first,&arr[i].second);
            arr[i].first *= 60000; //convert the minutes into millisecond.
            arr[i].second *= 60000;
        }
		// arrange only first
        sort(arr,arr+n);

        ans = 0;
        do
        {
            int temp = binary_search();
            ans = (temp > ans) ? temp : ans;

        }while(next_permutation(arr,arr+n));

        int secs = round( (double)ans / 1000.0 ); //round to closest second from milliseconds.
        int mins = secs / 60;
        secs %= 60;
        printf("Case %d: %d:%02d\n",++caseID,mins,secs);
    }
    return 0;
}
