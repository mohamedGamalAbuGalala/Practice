#include <bits/stdc++.h>

#define pb push_back
#define up upper_bound
#define lp lower_bound
#define pr pair<int,int>
#define ll long long int

using namespace std;

bool isPal(string inp) {
	int l = 0, r = inp.size() - 1;

	while (l < r) {

		while (l < r && !isalpha(inp[l]))
			l++;
		while (l < r && !isalpha(inp[r]))
			r--;

		//			cout << inp[l] << " " << inp[r] << " , ";

		if (l < r) {
			if (tolower(inp[l]) != tolower(inp[r]))
				return 0;
			l++, r--;
		}
	}
	return 1;
}

int main() {
	string inp;
	while (getline(cin, inp), inp != "DONE") {

		if (isPal(inp))
			cout << "You won't be eaten!\n";
		else
			cout << "Uh oh..\n";
	}
	return 0;
}
