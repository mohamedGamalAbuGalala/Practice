#include <iostream>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <algorithm>
#include <string.h>
#include <array>
#include <iterator>
#include <set>
#include <cmath>
#include<iomanip>	// Stew(10)		::        12	........ 8 spaces and 2 digits in 10 padding right

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

string home;

bool cmp(pair<string, string> b, pair<string, string> a) {
	if (b.first == home && a.first != home)
		return 1;
	return 0;
}

int main() {
	int n, cnt = 0;
	bool found = 1;
	vector<pair<string, string>> dat;
	cin >> n >> home;
	for (int i = 0; i < n; ++i) {
		pair<string, string> p;
		vector<string> sp;
		string inp;
		cin >> inp;
		split(inp, "->", sp);
		p.first = sp[0], p.second = sp[1];
		cnt = (p.first == home) ? cnt + 1 : cnt;
		dat.pb(p);
	}
	sort(dat.begin(), dat.end(), cmp);

	for (int i = 0; i < cnt && found; ++i) {
		int counter = 1;
		found = 0;

		for (int k = 0; k < cnt; ++k) {
			if (k == i)
				continue;
			if (dat[i].second == dat[k].second)
				counter++;
		}

		int fnded = 0;
		for (int j = cnt; j < n; ++j) {
			if (dat[j].first == dat[i].second)
				fnded++;
		}

		if(fnded == counter)
			found = 1;

		if (!found) {
			cout << "contest" << endl;
			return 0;
		}
	}
	cout << "home" << endl;
	return 0;
}
