#include <bits/stdc++.h>
using namespace std;

long long int data[100005];

int main() {
    long long int T, n , i ,res;
    cin>>T;
    while(T--){
        res =0 ;
        cin>>n;
        for (i = 0; i < n && cin>> data[i]; i++);
        
        if(n==1) {
            while(data[0] >1 )
                data[0]--,res++;
           cout<<res<<endl;
           continue;
        }
        int l = 0 , r = n-1 ;
        int ll = l+1 , rr = r-1 , mn = 1, midx = -1;
        
        // first is one
        if(data[l] > mn){
           res += data[l] - mn;
           data[l] = mn;
        }
        if(data[r] > mn){
           res += data[r] - mn;
           data[r] = mn;
        }
           
        
        // no other ones
        while(data[ll] == mn)
            data[ll-1] = 0 , res+= mn,ll++;
        while(data[rr] == mn)
            data[rr+1] = 0 , res+=mn,rr--;
            
        // reset the l & r to the first ones
        while(data[l] == 0)
            l++;
        while(data[r] == 0)
            r--;
    
        // the next is the 2 height block then increasing 2 3 4 5 4 3 2
        while(l <= r){
            
            // make sure it's on th i'th height block (e.g. 3 3 4 5 4 3 2) i'th block is 2 so decrease it till 2
            if(data[l] > mn){
               res += data[l] - mn;
               data[l] = mn;
            }
            /*else if(data[l] < mn){
               res += data[l];
               data[l] = 0;
            }*/
            if(data[r] > mn){
                res += data[r] - mn;
                data[r] = mn;
            }
            /*else if(data[r] < mn){
               res += data[r];
               data[r] = 0;
            }*/
            
            if((data[l] == data[l-1]) && (data[r] == data[r+1]))
                mn--;
            l++,r--,mn++;
        }
	   
        //cout<< mn <<"\n";
        // start feedback to check such state 1 2 6 2 2 1 to get to 1 2 6 2 1 0
        mn--;
        
        /*for (int i = 0; i < n; i++) {
            cout<<data[i] <<" ";
        }*/
        
        //cout<< "\n" << mn << " " << res<<"\n";
        
        int midxl = -1, midxr = -1;
        
        for (i = 0; i < n && data[i] < mn; i++);
        // max index
        midxl = i;
        
        
        for (i = n-1; i >= 0 && data[i] < mn; i--);
        
        midxr = i;
        
        midx = (midxr + midxl) / 2;
        
        l = midx -1;
        // if(data[midx] == data[midx+1])
        //     r = midx +2;
        // else
        
        r = midx +1;
            
        int mx =  --mn;
        // cout<<mx <<" " << mn <<"\n";
        for (int j = r; j < n; j++ , mn--) {
            // cout<< j <<" " << data[j] <<" " << mn << endl; 
            if(data[j] > mn){
                    res += data[j] - mn;
                    data[j] = mn;
            }
        }
        
        for (int j = l; j >= 0; j-- , mx--) {
            // cout<< j <<" " << data[j] <<" " << mx << endl; 
            if(data[j] > mx){
                    res += data[j] - mx;
                    data[j] = mx;
           }
        }
   
        cout << res << endl;
    }
    return 0;
}
/*
6
7
1 2 2 6 2 2 1
6
1 2 2 6 2 1
6
1 2 6 2 2 1
13
1 2 3 4 5 6 6 6 5 4 3 2 1
12
1 2 3 4 5 5 6 5 4 3 2 1
12
1 2 3 4 5 6 5 5 4 3 2 1
*/
