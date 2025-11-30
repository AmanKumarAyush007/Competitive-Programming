#include<bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h" 
#else
#define debug(x...)
#endif
#define int              int64_t
#define ff               first
#define ss               second
#define pb               push_back
#define inf              LLONG_MAX
#define hell             LLONG_MIN
#define nl               '\n'
#define all(a)           (a).begin(),(a).end()
#define rall(a)          (a).rbegin(),(a).rend()
#define sm(v)            accumulate(all(v),0LL)
#define inp(v)           for(auto& x : v) cin >> x;
#define setbit(x)        __builtin_popcountll(x)
#define lg(x)            (63 - __builtin_clzll(x)) //log base 2
#define prefixsum(a)     partial_sum(all(a), (a).begin());
#define suffixsum(a)     partial_sum(rall(a), (a).rbegin());

void solve(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>> st(n);
    vector<int> freq(m+1,0);

    for(int i=0;i<n;i++){
        int sz; cin >> sz;
        st[i].resize(sz);
        for(int j=0;j<sz;j++){
            cin >> st[i][j];
            freq[st[i][j]]++;
        }
    }

    for(int x=1;x<=m;x++){
        if(freq[x]==0){
            cout << "NO\n";
            return;
        }
    }

    int cnt = 1;

    for(int i = 0; i < n; i++){
        if(cnt == 3) break;
        bool check = true;
        for(int j=0;j < st[i].size();j++){
            if(freq[st[i][j]] < 2){
                check = false;
                break;
            }
        }
        if(check) cnt++;
    }

    if(cnt >= 3) cout << "YES" << nl;
    else cout << "NO\n"; 
    
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
