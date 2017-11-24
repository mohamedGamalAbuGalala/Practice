#include <iostream>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <algorithm>
#include <string.h>
#include <array>
#include <iterator>
#include <set>

#define pb push_back
#define up upper_bound
#define lp lower_bound

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
	set<string> s;
	string inp;
	getline(cin, inp);
	vector<string> splited;
	split(inp, " {,}", splited);
	for (int i = 0, size = splited.size(); i < size; ++i)
		s.insert(splited[i]);
	cout << s.size() << endl;
	return 0;
}
