#include <bits/stdc++.h>
using namespace std;
void file() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
#else
// online submission
//	freopen("alost.in", "r", stdin);
#endif
}

vector<int> graph[5010];
pair<int, int> countC[5010];
int isRoot[5010];
int N, D, C;
vector<int> nodes;
map<string, int> ntidx;
map<string, int>::iterator itn;
map<int, string> idxtn;

void dfs(int node, int depth) {
	if (depth >= D)
		countC[nodes[depth - D]].first--;
	nodes.push_back(node);
	for (int i = 0; i < (int) graph[node].size(); i++)
		dfs(graph[node][i], depth + 1);
	nodes.pop_back();
}

void print_result() {
	int ind = 0, fir;
	while (ind < C && countC[ind].first < 0 && ind < 3) {
		fir = countC[ind].first;
		vector<string> vec;
		while (ind < C && countC[ind].first == fir)
			vec.push_back(idxtn[countC[ind].second]), ind++;
		sort(vec.begin(), vec.end());
		fir *= -1;
		for (int i = 0; i < (int) vec.size(); i++)
			printf("%s %d\n", vec[i].c_str(), fir);
		vec.clear();
	}
}

int main() {
	file();
	int t, ind, fol, ind1;
	string name;
	cin >> t;
	for (int k = 1; k <= t; k++) {
		C = 0;
		memset(isRoot, 1, sizeof isRoot);
		cin >> N >> D;
		for (int i = 0; i < N; i++) {
			cin >> name;
			itn = ntidx.find(name);
			if (itn == ntidx.end()) {
				ntidx.insert(make_pair(name, C));
				idxtn.insert(make_pair(C, name));
				ind = C;
				C++;
			} else
				ind = itn->second;
			cin >> fol;
			for (int j = 0; j < fol; j++) {
				cin >> name;
				itn = ntidx.find(name);
				if (itn == ntidx.end()) {
					ntidx.insert(make_pair(name, C));
					idxtn.insert(make_pair(C, name));
					ind1 = C;
					C++;
				} else
					ind1 = itn->second;
				isRoot[ind1] = 0;
				graph[ind].push_back(ind1);
			}
		}
		for (int i = 0; i < C; i++)
			countC[i] = make_pair(0, i);
		for (int i = 0; i < C; i++)
			if (isRoot[i]) {
				ind = i;
				break;
			}
		dfs(ind, 0);
		sort(countC, countC + C);
		printf("Tree %d:\n", k);
		print_result();
		for (int i = 0; i < C; i++)
			graph[i].clear();
		nodes.clear();
		ntidx.clear();
		idxtn.clear();
	}

	return 0;
}
/*




















 scanf("%[^\n]%c",n);
 */
