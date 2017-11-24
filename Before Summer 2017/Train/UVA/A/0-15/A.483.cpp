#include <bits/stdc++.h>

#define pb push_back
#define up upper_bound
#define lp lower_bound
#define pr pair<int,int>
#define ll long long int

using namespace std;

void split(const string &s, const char* delim, vector<string> & v) {
	// to avoid modifying original string
	// first duplicate the original string and return a char pointer then free the memory
	char * dup = strdup(s.c_str());
	char * token = strtok(dup, delim);
	while (token != NULL) {
		v.push_back(string(token));
		// the call is treated as a subsequent calls to strtok:
		// the function continues from where it left in previous invocation
		token = strtok(NULL, delim);
	}
	free(dup);
}

int main() {
	string inp;
	while (getline(cin, inp)) {
		vector<string> sp;
		split(inp, " ", sp);
		for (int i = 0, si = sp.size(); i < si; ++i) {
			for (int j = sp[i].size() - 1; j >= 0; --j) {
				cout << sp[i][j];
			}
			if (i < si - 1)
				cout << " ";
		}
		cout << "\n";
	}
	return 0;
}
