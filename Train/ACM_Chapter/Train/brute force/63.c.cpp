#include <bits/stdc++.h>
using namespace std;

void file() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
//	freopen("ot.txt", "w", stdout);
#else
//	freopen("jumping.in", "r", stdin);	// HERE
#endif
}
//------------------------------------------------------------------------------Defines

//------------------------------------------------------------------------------

int n, arr[15][3];

bool distinct(int num) {
	set<int> st;
	for (int i = 0; i < 4; i++)
		st.insert(num % 10), num /= 10;
	return (st.size() == 4);
}

bool bulls(int num, int idx) {
	int cnt = 0, ex = arr[idx][0];
	for (int i = 0; i < 4; i++)
		cnt += (num % 10 == ex % 10), num /= 10, ex /= 10;
	return (cnt == arr[idx][1]);
}

bool cows(int num, int idx) {
	int cnt = 0;
	string ex = to_string(arr[idx][0]), ans = to_string(num);
	if (ex.length() == 3)
		ex = "0" + ex;
	if (ans.length() == 3)
		ans = "0" + ans;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (i == j)
				continue;
			if (ans[i] == ex[j])
				cnt++;
		}
	}
	return (cnt == arr[idx][2]);
}

bool check(int num) {
	if (!distinct(num))
		return false;
	bool ret = true;
	for (int i = 0; i < n; i++)
		ret &= (bulls(num, i) && cows(num, i));
	return ret;
}

int main() {
	file(); //TODO
	cin >> n;
	vector<int> sols;
	for (int i = 0; i < n; i++)
		cin >> arr[i][0] >> arr[i][1] >> arr[i][2];

	for (int ans = 123; ans <= 9876; ans++)
		if (check(ans))
			sols.push_back(ans);

	if (sols.empty()) {
		cout << "Incorrect data";
	} else if (sols.size() == 1) {
		if (sols[0] < 1000)
			cout << 0;
		cout << sols[0];
	} else
		cout << "Need more data";
	return 0;
}
