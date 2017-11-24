#include <bits/stdc++.h>

#define pb push_back
#define up upper_bound
#define lp lower_bound
#define pr pair<int,int>
#define ll long long int

using namespace std;

int main() {
	string tmp;
	map<string, string> mp;
	map<string, string>::iterator it;
	while (getline(cin, tmp) && !tmp.empty()) {
		stringstream ss(tmp);
		string s1, s2;
		ss >> s1 >> s2;
		mp[s2] = s1;
	}
	while (cin >> tmp) {
		it = mp.find(tmp);
		if (it == mp.end())
			cout << "eh\n";
		else
			cout << it->second << "\n";
	}
	return 0;
}
