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
#include <map>

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
	map<string,string> m;
	string  home;
	int n;
	cin >> n >> home;
	for (int i = 0; i < n; ++i) {
		vector<string> sp;
		string inp;
		cin >> inp;
		split(inp, "->", sp);
		m[sp[0]]= sp[1];
	}

	  for (map<string,string>::iterator it=m.begin(); it!=m.end(); ++it){

		  map<string,string>::iterator founded;

		  founded = m.find(it->second);
		  if (founded == m.end())
		    {
			  cout<<"contest";
			  return 0;
		    }
	  }

	cout<<"home";
	return 0;
}
