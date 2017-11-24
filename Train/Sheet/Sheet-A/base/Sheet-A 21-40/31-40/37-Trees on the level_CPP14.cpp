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

vector<pair<int, string>> ar[257];
vector<string> dat;
int mx;

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

int calc(string s) {
	int res = 0;
	for (int i = 0, si = s.size(); i < si; ++i) {
		if (s[i] == 'R')
			res = (res * 2) + 1;
		else
			res = (res * 2);
	}
	return res;
}

bool dubl(string v, int i) {
	vector<string>::iterator it = find(dat.begin(), dat.end(), v);
	int ind = it - dat.begin();
	if (it != dat.end() && ind != i)
		return 1;
	return 0;
//	for (int j = 0, si = dat.size(); j < si; ++j) {
//		if (dat[j] == v && j != i)
//			return 1;
//	}
//	return 0;
}

bool found_parent(string v) {
	vector<string>::iterator it = find(dat.begin(), dat.end(), v);
	if (it != dat.end())
		return 1;
	return 0;
//	for (int i = 0, si = dat.size(); i < si; ++i) {
//		if(dat[i] == v)
//			return 1;
//	}
//	return 0;
}

bool ok() {
	bool ft = 0, pnf = 0;
	for (int i = 0, siz = dat.size(); i < siz; ++i) {
		string cur = dat[i];
		if (dubl(cur, i))
			ft = 1;
		string p = cur.substr(0, cur.size() - 1);
		if (p.size() == 0)
			p = "r";
		if (cur != "r")
			if (!found_parent(p))
				pnf = 1;
	}
	return (!ft && !pnf);
}

bool cmp(pair<int, string> b, pair<int, string> a) {
	if (a.first > b.first)
		return 1;
	return 0;
}

void print() {
	if (ok()) {
		if (ar[0].size() != 0)
			cout << ar[0][0].second;
		for (int i = 1; i <= mx; ++i) {
			sort(ar[i].begin(), ar[i].end(), cmp);
			for (int j = 0, si = ar[i].size(); j < si; ++j) {
				cout << ' ' << ar[i][j].second;
			}
		}
		cout << '\n';
	} else
		cout << "not complete\n";
	vector<pair<int, string>> tmp;
	memset(ar, 0, sizeof ar);
	dat.clear();
	mx = 0;
}

int main() {
	string inp;
	while (cin >> inp) {
		if (inp == "()")
			print();
		vector<string> sp;
		split(inp, "(,)", sp);
		pair<int, string> tmp;
		if (sp.size() == 1) {
			dat.pb("r");
			tmp.first = 0, tmp.second = sp[0];
			ar[0].pb(tmp);
			mx = max(0, mx);
		} else if (sp.size() == 2) {
			dat.pb(sp[1]);
			tmp.first = calc(sp[1]), tmp.second = sp[0];
			ar[sp[1].size()].pb(tmp);
			int length = sp[1].size();
			mx = max(length, mx);
		}
	}
	return 0;
}

/* Test-Cases
 *
 *
 (11,LL) (7,LLL) (8,R)
 (5,) (4,L) (13,RL) (2,LLR) (1,RRR) (4,RR) (20,LR) (19,LRL) (18,LRR) (17,RLL) (16,RLR) (15,RRL) ()
 (3,L) (4,R) ()
 (11,LL) (7,LLL) (8,R)
 (5,) (4,L) (13,RL) (2,LLR) (2,LLR) (1,RRR) (4,RR) (20,LR) (19,LRL) (18,LRR) (17,RLL) (16,RLR) (15,RRL) ()
 (3,L) (4,R) (4,) ()
 (5,) ()
 ()


 5 4 8 11 20 13 4 7 2 19 18 17 16 15 1
 not complete
 not complete
 4 3 4
 5
 not complete
 *
 */
