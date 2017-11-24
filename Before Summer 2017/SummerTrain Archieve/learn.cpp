
// glala
// by bu-galala
#include <iostream>
#include <algorithm>
using namespace std;
int L[1000001], R[1000001], n, arr[101], cntR = 0, cntL = 0, ar[3], ans = 0;
#define LH(a , b , c) ((a*b)+c)
#define RH(d , e , fe) ((fe+e)*d)
void solve(int in) {
	if (in == 3) {
		int l = LH(ar[0], ar[1], ar[2]);
		int r = RH(ar[0], ar[1], ar[2]);
		L[cntR] = l;
		cntR++;
		if (ar[0] == 0)
			return;
		R[cntL] = r;
		cntL++;
		return;
	}
	for (int i = 0; i < n; i++) {
		ar[in] = arr[i];
		solve(in + 1);
	}
	return;
}
int main(void) {
	cin >> n;
	for (int i = 0; i < n && cin >> arr[i]; i++)
		;
	solve(0);
	sort(L, L + cntL);
	for (int i = 0; i < cntR; i++)
		ans +=
				(upper_bound(L, L + cntL, R[i]) - lower_bound(L, L + cntR, R[i]));
	cout << ans << endl;
	return 0;
}

/*
 //============================================================================
 // Name        : learn.cpp
 // Author      :
 // Version     :
 // Copyright   : Your copyright notice
 // Description : Hello World in C++, Ansi-style
 //============================================================================

 #include <iostream>
 #include <algorithm>
 using namespace std;

 void even(int x) {
 if (x == 0) {
 cout<<"even"<<endl;
 return;
 } else if(x == 1) {
 cout<<"even"<<endl;
 return;
 }else {
 even(x - 2);
 }
 }



 int main() {
 //	cout << "!!!Hello World!!" << endl; // prints !!!Hello World!!!

 even(100);
 return 0;
 }

 */
