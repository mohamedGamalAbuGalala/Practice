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

int main() {
	string inp, rem;
	getline(cin, inp);
	getline(cin, rem);
	vector<string> sp;
	string l;
	string r;
	if (inp != "|")
		split(inp, "|", sp);
	if (sp.size() == 2)
		l = sp[0], r = sp[1];
	else if(sp.size() == 0)
		l = "" , r = "";
	else if (inp[0] == '|')
		l = "", r = sp[0];
	else if (inp[0] != '|')
		l = sp[0], r = "";
	else
		l = "", r = "";

	if ((l.size() + r.size() + rem.size()) % 2 != 0) {
		cout << "Impossible";
		return 0;
	}
	int ind = 0, sir = rem.size();
	while (l.size() < r.size() && ind < sir)
		l.pb(rem[ind++]);
	while (l.size() > r.size() && ind < sir)
		r.pb(rem[ind++]);
	int id = 1;
	for (int i = ind, si = rem.size(); i < si; ++i) {
		if (id == 1)
			l.pb(rem[i]);
		else
			r.pb(rem[i]);
		id = 1 - id;
	}
	if (l.size() != r.size()) {
		cout << "Impossible";
		return 0;
	}
	for (int i = 0, si = l.size(); i < si && cout << l[i]; ++i)
		;
	cout << "|";
	for (int i = 0, si = r.size(); i < si && cout << r[i]; ++i)
		;
	return 0;
}
