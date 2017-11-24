#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <string.h>
#include <array>
#include <iterator>

#define pb push_back
#define up upper_bound
#define lp lower_bound

using namespace std;
int main() {
	int cnt = 0;
	string inp;
	cin>>inp;
	for (int i = 0 , s = inp.size() ; i < s; ++i)
		if((inp[i] == '4') || inp[i] == '7')
			cnt++;
	if(cnt == 7 || cnt == 4)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
	return 0;
}
