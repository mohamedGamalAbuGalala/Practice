#include <bits/stdc++.h>

#define pb push_back
#define up upper_bound
#define lp lower_bound
#define pr pair<int,int>
#define ll long long int

using namespace std;

int main() {
	freopen("in.txt", "r", stdin);
	int T;
	scanf("%d\n", &T);
	while (T--) {
		string inp;
		getline(cin, inp);
		int inpsi = inp.size(), inpsqrt = sqrt(inpsi), cnt = 0;
		if (inpsi != (inpsqrt * inpsqrt)) {
			cout << "INVALID\n";
			continue;
		}
		char ar[inpsqrt][inpsqrt];

		for (int i = 0; i < inpsqrt; ++i)
			for (int j = 0; j < inpsqrt; ++j)
				ar[i][j] = inp[cnt++];

		for (int i = 0; i < inpsqrt; ++i)
			for (int j = 0; j < inpsqrt; ++j)
				cout<<ar[j][i];
		cout<<"\n";
	}
	return 0;
}
