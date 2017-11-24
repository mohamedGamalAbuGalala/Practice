#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
typedef pair<int, int> pii;
typedef long long ll;
const ll INF = 0x3f3f3f3f;

struct Edge {
    int id, to;
};

const int MAX_N = 1000;
const int MAX_M = 10000;
int N, M, L, S, T;
ll w[MAX_M];
vector<pii> E;
vector<int> varE;
vector<Edge> g[MAX_N];

typedef pair<ll, int> P;
ll dijkstra(int s, int t) {
    vector<ll> d(N, INF);
    priority_queue<P, vector<P>, greater<P>> pq;
    d[s] = 0;
    pq.push(P(0ll, s));
    while (!pq.empty()) {
        P p = pq.top(); pq.pop();
        ll dis = p.st; int v = p.nd;
        if (dis > d[v]) continue;
        for (Edge& e : g[v]) {
            if (d[e.to] > d[v] + w[e.id]) {
                d[e.to] = d[v] + w[e.id];
                pq.push(P(d[e.to], e.to));
            }
        }
    }
    return d[t];
}

int main() {
    scanf("%d %d %d %d %d", &N, &M, &L, &S, &T);
    for (int i = 0; i < M; i++) {
        int u, v, z; scanf("%d %d %d", &u, &v, &z);
        E.push_back(pii(u, v));
        g[u].push_back((Edge) {i, v});
        g[v].push_back((Edge) {i, u});
        w[i] = z;
        if (z == 0)
            varE.push_back(i);
    }

    for (int id : varE)
        w[id] = 1;
    ll best = dijkstra(S, T);

    for (int id : varE)
        w[id] = INF;
    ll worst = dijkstra(S, T);

    if (best > L || worst < L) {
        puts("NO");
        return 0;
    }

    puts("YES");
    if (worst > L) {
        for (int id : varE)
            w[id] = INF;

        for (int id : varE) {
            w[id] = 1;
            int dis = dijkstra(S, T);
            if (dis <= L) {
                w[id] += (L - dis);
                break;
            }
        }

    }

    for (int id = 0; id < M; id++) {
        printf("%d %d %lld\n", E[id].st, E[id].nd, w[id]);
    }

    return 0;
}
