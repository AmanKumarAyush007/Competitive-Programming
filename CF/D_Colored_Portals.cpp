#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

const long long INF = 1e18;

void solve() {
    int n;
    long long q;
    cin >> n >> q;

    // Adjacency list for our graph: {neighbor_node, edge_weight}
    vector<vector<pair<int, int>>> adj(n);
    map<char, vector<int>> cities_by_color;

    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        cities_by_color[s[0]].push_back(i);
        cities_by_color[s[1]].push_back(i);
    }

    // Build the sparse graph
    for (auto const& [color, cities] : cities_by_color) {
        // Sorting is not strictly needed as we read in order, but good practice
        // sort(cities.begin(), cities.end()); // Cities are already sorted by index
        for (size_t i = 0; i < cities.size(); ++i) {
            if (i > 0) {
                int u = cities[i-1];
                int v = cities[i];
                int weight = abs(u - v);
                adj[u].push_back({v, weight});
                adj[v].push_back({u, weight});
            }
        }
    }

    for (int k = 0; k < q; ++k) {
        int start_node, end_node;
        cin >> start_node >> end_node;
        --start_node; // Use 0-based indexing
        --end_node;

        if (start_node == end_node) {
            cout << 0 << "\n";
            continue;
        }

        // Dijkstra's Algorithm for each query
        vector<long long> dist(n, INF);
        // Priority queue stores {cost, node}. Use negative cost for min-heap behavior.
        priority_queue<pair<long long, int>> pq;

        dist[start_node] = 0;
        pq.push({0, start_node});

        long long result = -1;

        while (!pq.empty()) {
            long long d = -pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if (u == end_node) {
                result = d;
                break;
            }

            // If we found a shorter path already, skip
            if (d > dist[u]) {
                continue;
            }

            // Relax edges for neighbors
            for (auto const& edge : adj[u]) {
                int v = edge.first;
                int weight = edge.second;
                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push({-dist[v], v});
                }
            }
        }
        cout << result << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
