#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
 cul.,f,..fluc   culffluc   8
 cul.,f,..fluc Madam, I'm Adam
 dsfljkz.,z/'sdxzmooom
 sdfkjl;kxz/,x'zxlmoooom
 Madam, I'm Adam
 */

int main() {
	string s, in;
	int first;
	int x, y;
	getline(cin, in);
	for (int i = 0; i < in.length(); i++) {
		if ((in[i] >= 'A' && in[i] <= 'Z') || (in[i] >= 'a' && in[i] <= 'z')) {
			s.push_back(tolower(in[i]));
		} else {
			continue;
		}
	}
	int len = s.length();
	int maxlen = 0;
	for (int i = 0; i < len; i++) {
		y = i;
		x = i - 1;
		while (x >= 0 && y < len && tolower(s[x]) == tolower(s[y])) {
			if (y - x + 1 > maxlen) {
				first = x;
				maxlen = y - x + 1;
			}
			--x;
			++y;
		}

		y = i + 1;
		x = i - 1;
		while (x >= 0 && y < len && tolower(s[x]) == tolower(s[y])) {
			if (y - x + 1 > maxlen) {
				first = x;
				maxlen = y - x + 1;
			}
			--x;
			++y;
		}

	}
	cout << maxlen << endl;
	for (int i = first; i < first + maxlen; i++) {
		cout << s[i];
	}
	cout << endl;
	return 0;
}
