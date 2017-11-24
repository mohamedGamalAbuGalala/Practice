#include <bits/stdc++.h>

#define pb push_back
#define up upper_bound
#define lp lower_bound
#define pr pair<int,int>
#define ll long long int

using namespace std;

string start;
map<string, int> v;
map<string, int> sh;

map<string,int> visited;

int bfs(string start, string to, map< string,vector<string> > graph){

  queue<string> s;
  s.push(start);
  visited[start]=0;
  while(s.empty()==false){
    string top = s.front();
    s.pop();
    if(top==to)
      return visited[top];
    int total =graph[top].size();
    for (int i = 0; i < total; ++i)
    {
      if(!visited.count(graph[top][i])){
        visited[graph[top][i]]=visited[top]+1;
        s.push(graph[top][i]);
      }
    }
  }
}


void dfs(string s, string e, map<string, vector<string> > mp, int res) {

	if (s == e)
		return;

	v[s] = 1;
	map<string, vector<string>>::iterator fit;
	fit = mp.find(s);
	int fsi = fit->second.size();

	for (int i = 0; i < fsi; ++i)
		if (sh[fit->second[i]] == 0 && fit->second[i] != start)
			sh[fit->second[i]] = res + 1;

	for (int i = 0; i < fsi; ++i)
		if (v[fit->second[i]] != 1)
			dfs(fit->second[i], e, mp, sh[fit->second[i]]);

}

int main() {
	freopen("in.txt", "r", stdin);
	int n;
	scanf("%d", &n);
	while (n--) {
		map<string, vector<string>> mp;
		map<string, vector<string>>::iterator fit;
		string inp;
		scanf("\n");
		while (cin >> inp) {
			if (inp == "*")
				break;
			mp[inp];
			fit = mp.find(inp);
			for (map<string, vector<string>>::iterator it = mp.begin();
					it != mp.end(); ++it) {

				int dif = 0, insi = inp.size(), itsi = it->first.size();
				if (insi != itsi)
					continue;
				for (int i = 0; i < insi; ++i) {
					if (inp[i] != it->first[i])
						dif++;
				}
				if (dif == 1) {
					fit->second.pb(it->first);
					it->second.pb(inp);
				}
			}
		}
		scanf("\n");

		string tmp;
		while (getline(cin, tmp) && !tmp.empty()) {
			stringstream ss(tmp);
			string s1, s2;
			ss >> s1 >> s2;
//			v.clear();
//			sh.clear();
			visited.clear();
//			start = s1;
//			sh[s1] = 0;
//			dfs(s1, s2, mp, 0);
//			cout << s1 << " " << s2 << " " << sh[s2] << "\n";
			cout << s1 << " " << s2 << " " << bfs(s1,s2,mp) << "\n";
		}
		if (n)
			cout << "\n";
	}
	return 0;
}
