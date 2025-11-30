#include <bits/stdc++.h>
using namespace std;
#define int long long

struct Edge {
    int u, v, w;
};

void solve() {
    int n, m;
    cin >> n >> m;

    vector<Edge> edges(m);
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
        edges[i].u--;
        edges[i].v--;
    }

    vector<int> dist(n, 1e18);
    vector<int> parent(n, -1);
    dist[0] = 0;

    int x = -1; // will store last updated vertex

    // Relax edges n times (nth time to check cycle)
    for (int i = 0; i < n; i++) {
        x = -1;
        for (auto &e : edges) {
            if (dist[e.u] + e.w < dist[e.v]) {
                dist[e.v] = dist[e.u] + e.w;
                parent[e.v] = e.u;
                x = e.v;
            }
        }
    }

    if (x == -1) {
        cout << "NO\n";
    } else {
        cout << "YES\n";

        // backtrack to find a vertex inside the cycle
        int y = x;
        for (int i = 0; i < n; i++)
            y = parent[y];

        // reconstruct cycle
        vector<int> cycle;
        for (int cur = y;; cur = parent[cur]) {
            cycle.push_back(cur);
            if (cur == y && cycle.size() > 1)
                break;
        }
        reverse(cycle.begin(), cycle.end());

        for (auto v : cycle)
            cout << v + 1 << " ";
        cout << "\n";
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
