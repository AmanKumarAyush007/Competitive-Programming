#include <bits/stdc++.h>
using namespace std;

#define int int64_t
const int INF = 1000000000;

struct Seg {
    int n, sz;
    vector<int> t;

    Seg(int n_) {
        n = n_;
        sz = 1;
        while (sz < n) sz <<= 1;
        t.assign(2 * sz, INF);
        for (int i = 0; i < n; i++) t[sz + i] = i;
        for (int i = sz - 1; i > 0; i--) {
            t[i] = min(t[2 * i], t[2 * i + 1]);
        }
    }

    void upd(int idx, int val) {
        int i = sz + idx;
        t[i] = val;
        i >>= 1;
        while (i) {
            t[i] = min(t[2 * i], t[2 * i + 1]);
            i >>= 1;
        }
    }

    int qry(int l, int r) {
        l += sz;
        r += sz;
        int res = INF;
        while (l <= r) {
            if (l & 1) {
                res = min(res, t[l]);
                l++;
            }
            if (!(r & 1)) {
                res = min(res, t[r]);
                r--;
            }
            l >>= 1;
            r >>= 1;
        }
        return res;
    }
};

void solve() {
    int n, k, m;
    cin >> n >> k >> m;

    vector<vector<pair<int,int>>> occ(n + 1);
    vector<vector<int>> rt(m);

    for (int i = 0; i < m; i++) {
        int len;
        cin >> len;
        rt[i].resize(len);
        for (int j = 0; j < len; j++) {
            cin >> rt[i][j];
            if (rt[i][j] <= n) {
                occ[rt[i][j]].push_back({i, j});
            }
        }
    }

    vector<int> dist(n + 1, INF);
    dist[1] = 0;
    queue<int> q;
    q.push(1);

    vector<Seg> seg;
    seg.reserve(m);
    for (int i = 0; i < m; i++) {
        seg.emplace_back((int)rt[i].size());
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        int du = dist[u];

        vector<pair<int,int>> &vec = occ[u];
        for (size_t idx = 0; idx < vec.size(); idx++) {
            int id = vec[idx].first;
            int pos = vec[idx].second;

            Seg &st = seg[id];
            int len = (int)rt[id].size();

            int L = pos + 1;
            int R = min(pos + k, len - 1);
            if (L > R) continue;

            while (true) {
                int np = st.qry(L, R);
                if (np == INF || np > R) break;

                int v = rt[id][np];
                if (dist[v] == INF) {
                    dist[v] = du + 1;
                    q.push(v);
                }
                st.upd(np, INF);
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (dist[i] == INF) ans += i * (-1);
        else ans += i * dist[i];
    }

    cout << ans << "\n";
}

signed main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("C:/Users/desktop/Downloads/final/designing_paths_input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}