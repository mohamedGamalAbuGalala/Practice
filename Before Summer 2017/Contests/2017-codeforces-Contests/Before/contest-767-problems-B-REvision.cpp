#include <iostream>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <algorithm>
#include <string.h>
#include <array>
#include <iterator>
#include <set>
#include <cmath>
#include<iomanip>	// Stew(10)		::        12	........ 8 spaces and 2 digits in 10 padding right

#define pb push_back
#define up upper_bound
#define lp lower_bound
#define pr pair<int,int>
#define ll long long int

using namespace std;

int main() {

    long long start , finish , spend , free , t;
    cin>>start>>finish>>spend;
    free = start;

    int n;
    cin>>n;

    pair <long long , long long > ans ;

    ans.first = -1;
    ans.second = 1e13;

    for(int i = 0 ; i<n ; i++){
        cin>>t;
        if ((t > free) && (free + spend <= finish) && ans.second ){
            ans.first = free;
            ans.second = 0;
        }
        if(t && (ans.second > free -  t + 1) && (free + spend <= finish) && ans.second){
            ans.first = t-1 ;
            ans.second = ( free - ans.first >= 0 ? free - ans.first : 0 );
        }

        free = spend + max(free,t);
    }

    if((free < finish) && (free + spend <= finish) && ans.second){
        ans.first = free;
        ans.second = 0;
    }

    cout<<ans.first;

	/*
	int s, e, inter, n;
	cin >> s >> e >> inter >> n;
	int ar[n];
	for (int i = 0; i < n && cin >> ar[i]; ++i)
		;
	int res = ar[0] - 1;
	for (int i = 0; i < n && s < e; ++i) {
		if (ar[i] <= s) {
			s += inter;
			continue;
		}
		if (ar[i] > s && s <= e - inter) {
			res = s;
			break;
		}
	}
	if (s <= e - inter)
			res = s;
	cout<<res;
	*/
	return 0;
}
