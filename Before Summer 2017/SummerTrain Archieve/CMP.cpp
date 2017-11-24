//============================================================================
// Name        : CMP.cpp
// Author      : glala
// Version     :
// Copyright   : Your copyright notice
// Description : order by even asc then odd desc
//============================================================================
//
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool cmp (int b , int a){
	if (b%2==0  && a % 2 == 0 )
		return a > b;
	if (b % 2 == 0 && a % 2 == 1)
		return true;
	if (a % 2 == 1 && (b % 2) == 1 )
		return a < b;
	return false ;
}

int main() {
    int arr[5];
    for (int i = 0; i < 5 && cin >> arr[i] ; i++);
    std::sort(arr , arr+5 , cmp);
    for (int i = 0; i < 5; ++i) {
		cout << arr[i];
	}
	return 0;
}
