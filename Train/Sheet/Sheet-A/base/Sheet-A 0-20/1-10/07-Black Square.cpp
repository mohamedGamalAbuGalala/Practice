#include <iostream>
#include <math.h>
using namespace std;
int main() {
	int a1, a2, a3, a4, res = 0 , s;
	string inp;
	cin >> a1 >> a2 >> a3 >> a4;
	cin >> inp;
	s= inp.size();
	for (int i = 0; i < s; ++i)
		(inp[i] == '1') ? res += a1 : (inp[i] == '2') ? res += a2 :
		(inp[i] == '3') ? res += a3 : res += a4;
	cout<<res<<endl;
	return 0;
}
