#include<bits/stdc++.h>
using namespace std;

#define int        int64_t
#define ff         first
#define ss         second
#define pb         push_back
#define inf        LLONG_MAX
#define hell       LLONG_MIN
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()
#define sm(v)      accumulate(all(v),0LL)
#define inp(v)     for(auto& x : v) cin >> x;
#define setbit(x)  __builtin_popcountll(x)


void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    inp(a)

    map<int, int> max_conti;
    int i = 0;
    while (i < n) {
        int j = i;
        while (j < n && a[j] == a[i]) {
            j++;
        }
        int len = j - i;
        if (max_conti.find(a[i]) != max_conti.end()) {
            if (len > max_conti[a[i]]) {
                max_conti[a[i]] = len;
            }
        } else {
            max_conti[a[i]] = len;
        }
        i = j;
    }

    int ans = inf;
    for (auto [a,b] : max_conti) {
        int cost = (n - b) * a;
        if (cost < ans) {
            ans = cost;
        }
    }
    cout << ans << nl;
}


signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}