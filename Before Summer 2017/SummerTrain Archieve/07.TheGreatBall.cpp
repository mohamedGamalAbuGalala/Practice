//============================================================================
// Name        : TheGreatBall.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <algorithm>
using namespace std;

class node {
public:
	int n, f;
};

node t[201];

bool cmp(node b, node a) {
	return a.n > b.n;
}

int main() {
	int k, i, s, e, j, ret;
	scanf("%d", &k);
	while (k) {
		k--;
		int n, cnt = 0;
		scanf("%d", &n);
		for (i = 0; i < n; ++i) {
			scanf("%d %d", &s, &e);
			t[cnt].n = s, t[cnt++].f = 0;
			t[cnt].n = e, t[cnt++].f = 1;
		}
		sort(t, (t + cnt), cmp);
		ret = 0, j = 0;
		for (i = 0; i < cnt; ++i) {
			if (t[i].f)
				j--;
			else
				j++;
			ret = max(ret, j);
		}
		printf("%d\n", ret);
	}
	return 0;
}
