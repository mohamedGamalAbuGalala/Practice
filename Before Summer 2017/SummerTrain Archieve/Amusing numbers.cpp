#include<iostream>
#include<algorithm>
using namespace std;

long long p[60] , k;

int main()
{
    int i,dig,cases;
    
    p[0] = 1;
    for(i=1;i<60;i++)
        p[i] = p[i-1] * 2;
    
    cin >> cases;
    while(cases--)
    {
        cin >> k;
        for(dig=1;k>p[dig];dig++)
            k -= p[dig];
        
        for(i=dig-1;i>-1;i--)
        {
            if(k <= p[i])
                cout << "5";
            else
            {
                cout << "6";
                k -= p[i];
            }
        }
        cout << endl;
    }
    return 0;
}
