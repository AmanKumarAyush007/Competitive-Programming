#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<pair<int, int>> dominoes;
        bool self_loop = false;
        for (int i = 0; i < n; i++) {
            int a, b;
            cin >> a >> b;
            dominoes.push_back({a, b});
            if (a == b) {
                self_loop = true;
            }
        }

        if (self_loop) {
            cout << "NO\n";
            continue;
        }

        vector<int> freq(n+1, 0);
        for (auto [a, b] : dominoes) {
            if (a >= 1 && a <= n) freq[a]++;
            if (b >= 1 && b <= n) freq[b]++;
        }

        bool valid = true;
        for (int i = 1; i <= n; i++) {
            if (freq[i] != 2) {
                valid = false;
                break;
            }
        }
        if (!valid) {
            cout << "NO\n";
            continue;
        }

        vector<vector<int>> adj(n+1);
        for (auto [a, b] : dominoes) {
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        vector<bool> visited(n+1, false);
        valid = true;
        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                queue<int> q;
                q.push(i);
                visited[i] = true;
                int count = 0;
                while (!q.empty()) {
                    int u = q.front(); q.pop();
                    count++;
                    for (int v : adj[u]) {
                        if (!visited[v]) {
                            visited[v] = true;
                            q.push(v);
                        }
                    }
                }
                if (count % 2 == 1) {
                    valid = false;
                    break;
                }
            }
        }

        if (valid) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}