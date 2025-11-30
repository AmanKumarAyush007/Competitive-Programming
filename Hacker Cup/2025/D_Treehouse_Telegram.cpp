#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX_N = 100000;
vector<vector<int>> dl;

void pd(int n) {
    dl.resize(n+1);
    for (int i=1; i<=n; i++) {
        for (int j=i; j<=n; j+=i) {
            dl[j].push_back(i);
        }
    }
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("C:/Users/desktop/Downloads/final/treehouse_telegram_input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif


    pd(MAX_N);
    
    
    int T;
    cin >> T;
    for (int t=1; t<=T; t++) {
        
        int N;
        cin >> N;
        vector<vector<int>> adj(N+1);
        for (int i=0; i<N-1; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<long long> G(N+1, 0);
        vector<vector<int>> children(N+1);
        vector<int> parent(N+1, 0);
        queue<int> q;
        q.push(1);
        parent[1] = 0;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : adj[u]) {
                if (v == parent[u]) continue;
                parent[v] = u;
                children[u].push_back(v);
                q.push(v);
            }
        }
        
        vector<int> order;
        q.push(1);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            order.push_back(u);
            for (int v : children[u]) {
                q.push(v);
            }
        }
        reverse(order.begin(), order.end());
        
        vector<unordered_map<int, int>> maps(N+1);
        
        for (int u : order) {
            for (int d : dl[u]) {
                if (d <= N) {
                    maps[u][d]++;
                }
            }
            for (int v : children[u]) {
                if (maps[u].size() < maps[v].size()) {
                    swap(maps[u], maps[v]);
                }
                for (auto &it : maps[v]) {
                    int d = it.first;
                    int cnt = it.second;
                    maps[u][d] += cnt;
                }
            }
            if (u != 1) {
                for (auto &it : maps[u]) {
                    int d = it.first;
                    int cnt = it.second;
                    if (d <= N) {
                        long long total_nodes = N / d;
                        G[d] += (long long) cnt * (total_nodes - cnt);
                    }
                }
            }
        }
        
        vector<long long> F(N+1, 0);
        for (int d = N; d >= 1; d--) {
            F[d] = G[d];
            for (int k=2; k*d <= N; k++) {
                F[d] -= F[k*d];
            }
        }
        
        cout << "Case #" << t << ":";
        for (int i=1; i<=N; i++) {
            cout << " " << F[i];
        }
        cout << endl;
    }
    return 0;
}