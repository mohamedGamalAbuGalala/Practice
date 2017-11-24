//============================================================================
// Name        : calfflac.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

/*
 cul.,f,..fluc   culffluc   8
 cul.,f,..fluc Madam, I'm Adam
 dsfljkz.,z/'sdxzmooom
 sdfkjl;kxz/,x'zxlmoooom
 Madam, I'm Adam
 */

 #include <iostream>
 #include <string>

 using namespace std;

 int main() {
 string inp;
 int l, r, len = 0, cnt = 0, i, j, iO[20000];
 char cO[20000];
 getline(cin, inp);
 //	cin >> inp;
 for (i = 0; i < inp.size(); ++i) {
 if (((inp[i] >= 'a' && inp[i] <= 'z')
 || (inp[i] >= 'A' && inp[i] <= 'Z'))) {
 if (inp[i] >= 'A' && inp[i] <= 'Z')
 cO[cnt] = inp[i] + 32;
 else
 cO[cnt] = inp[i];
 iO[cnt++] = i;
 }
 }
 for (i = 0; i < cnt; ++i) {
 int cl = i, cr = i + 1;
 // even
 while (cl >= 0 && cr < cnt && cO[cl] == cO[cr]) {
 if (len < (cr - cl)) {
 len = cr - cl;
 l = cl, r = cr;
 }
 cl--, cr++;
 }
 cl = i, cr = i + 1;
 // odd
 while (cl >= 0 && cr < cnt && cO[cl - 1] == cO[cr]) {
 if (len < (cr - (cl - 1))) {
 len = cr - (cl - 1);
 l = cl - 1, r = cr;
 }
 cl--, cr++;
 }
 }
 printf("%d\n", len + 1);
 for (i = iO[l]; i <= iO[r]; ++i)
 printf("%c", inp[i]);
 printf("\n");
 return 0;
 }
/*


#include <iostream>

#include <string>

using namespace std;

int main()

{

	string s;

	int first;

	int x, y;

	getline(cin, s);

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

 */
