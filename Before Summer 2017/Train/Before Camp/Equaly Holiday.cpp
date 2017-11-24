//============================================================================
// Name        : Equaly.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	vector <int> arr;
	int n, sum = 0;

	cin>>n;

	for (int i = 0; i < n ; ++i){
		int tmp ;
		cin>> tmp;
		arr.push_back(tmp);
	}

	sort(arr.begin() , arr.end());

	int max = arr[n-1];
	for (int i = 0; i < n; ++i) {
		if(arr[i] < max)
		{
			int tmp = max - arr[i];
			sum+=tmp;
		}
	}
	cout<<sum;


	return 0;
}
