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
    int n;
    cin >> n;
    vector<int> v(n);
    inp(v);

    sort(all(v));


    int ans = 0;
    
    for (int i = 0; i < n; i++){
        map<int,int> mp;
        int s = 0;
        for (int j = i; j < n; j++){
            s += v[j];
            mp[v[j]]++;
    
            int len = j - i + 1;
            if (len < 3) continue;
    
            int x1 = v[i], x2 = v[i+1], y = v[j];
            if (x1 + x2 <= y) continue;
    
            int o = 0;
            for (auto &[a,b] : mp) if (b % 2) o++;
            if (o >= 3) continue;
    
            ans = max(ans, s);
        }
    }

    cout << max(ans,0LL) << nl;
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