//============================================================================
// Name        : L_Path.cpp
// Author      : glala
// Version     :
// Copyright   : Your copyright notice
// Description :
//			1 5
//			2 4			>> 1 > 5 > 4 = 10
//___________________________________________
//			5 8 2
//			6 7 8
//			1 8 9		>> 5 > 8 > 7 > 8 > 9 = 37
//
//============================================================================

#include <iostream>
using namespace std;

int max_ = 3;

int arr[3][3];
int Mpath(int i , int j){
	if(i == max_ || j ==max_) return 0;
	if( i == max_  && j == max_)
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
