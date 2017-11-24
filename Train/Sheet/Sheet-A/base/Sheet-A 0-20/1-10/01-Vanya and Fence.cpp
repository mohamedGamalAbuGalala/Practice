#include <iostream>
using namespace std;
int main(){
	int tall , n , h , res = 0;
	cin>>n>>h;
	for (int i = 0; i < n; ++i) {
		cin>>tall;
		if(tall > h)
			res +=2;
		else
			res++;
	}
	cout<<res<<endl;
    return 0;
}
