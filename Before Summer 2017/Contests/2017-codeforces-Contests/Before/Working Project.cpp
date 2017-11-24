#include <iostream>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <algorithm>
#include <string.h>
#include <array>
#include <iterator>
#include <set>
#include <stack>
#include <cmath>
#include<iomanip>	// Stew(10)		::        12	........ 8 spaces and 2 digits in 10 padding right

#define pb push_back
#define up upper_bound
#define lp lower_bound
#define pr pair<int,int>
#define ll long long int

using namespace std;
int inx = 0;
bool arr1[100000005];
void bfs(long long n){
	stack<long long> q;
	q.push(n);

	while(!q.empty()){
		long long cur = q.top();
		q.pop();
		if(cur == 1 || cur == 0){
			arr1[inx] = cur;
			inx++;
		}else{
			long long temp1 = cur /2;
			long long temp2 = cur%2;
			q.push(temp1);
			q.push(temp2);
			q.push(temp1);
		}
	}
}

int main(){
    memset(arr1,0,sizeof arr1);
	long long n;
	long long r , l;
	scanf("%lld%lld%lld",&n,&r,&l);
	int ret = 0;
	bfs(n);

	for(int i = r ; i <= l  ; i++){
		if(arr1[i])
			ret++;
	}
	printf("%d",ret);
	return 0;
}
