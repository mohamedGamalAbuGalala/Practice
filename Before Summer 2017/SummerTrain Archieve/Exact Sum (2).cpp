// Exact Sum.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<algorithm>
using namespace std;

int n , arr[10001] , m;

int main()
{
	int i , first , second, ind;

	while(cin >> n)
	{
		for(i=0;i<n;i++)
			cin >> arr[i];
		cin >> m;

		sort(arr,arr+n);
		for(i=0;i<n && arr[i] <= m/2;i++)
		{
			ind = lower_bound(arr,arr+n, m-arr[i])-arr;
			if(ind != n && arr[ind] == m-arr[i])
				first = arr[i], second = m-arr[i];
		}
		cout << "Peter should buy books whose prices are " << first << " and " << second << ".\n\n";
	}

	return 0;
}
