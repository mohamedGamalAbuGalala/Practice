///Phone List (Trie Tree)

#include <iostream>
#include <string>
#include <vector>
#include <string.h>
using namespace std;

int n;
string arr[10000];
vector<int> node(10, -1);
vector< vector<int> > trie;
bool flag[100000];

int main() {
	int i, cases, cur, j;
	bool ans, temp;
	cin >> cases;
	while (cases--) {
		cin >> n;
		for (i = 0; i<n; i++)
			cin >> arr[i];

		memset(flag, 0, sizeof flag);
		trie.clear();
		trie.push_back(node);
		ans = 1;

		for (i = 0; i<n; i++) {
			cur = temp = 0;
			for (j = 0; j<arr[i].size(); j++) {
				int dig = arr[i][j] - '0';
				if (trie[cur][dig] != -1)
					cur = trie[cur][dig];
				else {
					temp = 1;///this phone number added a new node.
					trie[cur][dig] = trie.size();
					cur = trie.size();
					trie.push_back(node);
				}
				if (flag[cur]) {
					ans = 0;
					break;
				}
			}
			if (temp == 0) {
				ans = 0;
				break;
			}
			flag[cur] = 1;
		}
		if (ans == 1) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}
