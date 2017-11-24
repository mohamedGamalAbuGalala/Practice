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
	// using scanf() run in only ---------------------------------------62 ms
	int n ,tmp ,top;
	bool v[100001]={0};
	scanf("%d",&n);
	top = n;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &tmp);
		v[tmp]=1;
		while(v[top])
			printf("%d ",top--);
		printf("\n");
	}
	// same code with cin , cout  --------------------------------------373 ms
/*	int n, ar[100001], v[100001] = {0}, next;
	cin >> n;
	next = n;
	for (int i = 0; i < n; ++i) {
		cin >> ar[i];
		v[ar[i]] = 1;
		for (int j = next; j >= 1; --j) {
			next = j;
			if (v[j] == 1)
				v[j] = 0, cout << j << " ";
			else
				break;
		}
		cout << endl;
	}
*/
	return 0;
}
