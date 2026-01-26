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
    int n,k;
    cin >> n >> k;

    string a, b;
    cin >>  a >> b;

    vector<int> v(26,-1), uni;

    for(auto &ch : a){
        int c = ch - 'a';
        if(v[c] == -1){
            v[c] = uni.size();
            uni.pb(c);
        }
    }

    int uc = uni.size();
    int val = min(uc,k);

    int ans = 0;

    for(int bm = 0; bm < (1LL << uc); bm++){
        if(setbit(bm) != val) continue;

        int match = 0;
        int tot = 0;

        for(int i = 0; i < n; i++){
            if(a[i] == b[i] || (bm & (1LL << v[a[i] - 'a']))) match++;
            else {
                tot += (match*(match+1))/2;
                match = 0;
            }
        }

        tot += (match*(match+1))/2;
        
        ans = max(ans,tot);
    }


    cout << ans  << nl;
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