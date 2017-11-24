///Histogram (Nearest smaller element)
#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

int arr[100], n;
int val[100], ind[100], cnt = 0;
int res[100];

int main() {
	int i;

	cin >> n;
	for (i = 0; i<n; i++)
		cin >> arr[i];

	for (i = 0; i<n; i++) {
		while (cnt > 0 && val[cnt - 1] >= arr[i])
			cnt--;

		if (cnt == 0) res[i] = -1;
		if (cnt > 0) res[i] = ind[cnt - 1];

		val[cnt] = arr[i];
		ind[cnt] = i;
		cnt++;
	}

	for (i = 0; i<n; i++)
		cout << res[i] << endl;
	return 0;
}
