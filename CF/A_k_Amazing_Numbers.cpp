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

int mxDiff(vector<int> & v, int n){
    int diff = v[0];
    diff = max(diff,(n + 1 - v[v.size() - 1]));
    for(int i = 1; i < v.size(); i++){
        diff = max(v[i] - v[i-1],diff);
    }
    return diff;
}

void solve(){
    int n;
    cin >> n;
    vector<int> v(n+1,-1), ans(n+1,-1);

    map<int,vector<int>> mp;
    for(int i = 1; i <= n; i++){
        cin >> v[i];
        mp[v[i]].pb(i);
    }

    for(auto &[a,b] : mp){
        int x = mxDiff(b,n);
        while(x <= n && ans[x] == -1){
            ans[x] = a;
            x++;
        }
    }

    for(int i = 1; i <= n; i++){
        cout << ans[i] << " ";
    }

    cout << nl;
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