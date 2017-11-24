/*
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <stdint.h>
#include <typeinfo>
#include <vector>
using namespace std;

void printN(int x){
	if(x){
		printN(x /  10);
		cout<< x%10;
	}
}

void printND(int x){
	if(x){
		printN(x /  2);
		cout<< x%2;
	}
}

void print(int x) {
	if (x <= 0) {
		return;
	} else {
		print(x - 1);
		for (int i = 1; i <= x; ++i) {
			cout << "*";
		}
		cout << endl;
	}
}

int f3n_1(int n) {
	if (n == 1)
		return 1;
	if (n % 2 == 0)
		return 1 + f3n_1(n / 2);
	return 1 + f3n_1(3 * n + 1);
}

void printRev(int x) {
	if (x <= 0) {
		return;
	} else {
		for (int i = 1; i <= x; ++i) {
			cout << "*";
		}
		cout << endl;
		printRev(x - 1);
	}
}

int fact(int n) {
	if (n == 1) {
		return n;
	} else {
		// return fact >>>> * n;
		return fact(n - 1) * n;
	}
}

int max_ = 3;

int arr[3][3];
int Mpath(int i , int j){
	if(i == max_ || j ==max_) return 0;
	if( i == max_-1  && j == max_-1)
		return arr[i][j];
	int p1 = arr[i][j]+ Mpath(i,j+1);
	int p2 = arr[i][j]+ Mpath(i+1,j);
	return max(p1,p2);
}


int main(void){
	cout<<"hello"<<endl;
	for (int i = 0; i < 3; ++i){
		cin>>arr[i][0];
		cin>>arr[i][1];
		cin>>arr[i][2];
	}
	int res = Mpath(0,0);
	cout<<res<<endl;

	return 0;

}


int main(void) {
	cout<<"hello"<<endl;
//	for (int i = 0; i < 3; ++i){
//		cin>>arr[i][0];
//		cin>>arr[i][1];
//		cin>>arr[i][2];
//	}
//	int res = Mpath(0,0);
//	cout<<res<<endl;

	return 0;
//	printND(214);
//	printN(214);
//	int i = f3n_1(22);
//	cout << i << endl;
//	printRev(5);
//	print(5);
//	int x = fact(4);
//	cout << x << endl;
}

*/
