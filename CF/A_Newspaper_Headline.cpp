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
#define inf              (int)1e18
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
    string s,t;
    cin >> s >> t;

    vector<vector<int>> v(26);

    for(int i = 0; i < s.size(); i++){
        v[s[i] - 'a'].pb(i);
    }

    int ans = 1;
    int curr = 0;
    int ind = 0;

    for(auto &i : t){
        if(v[i-'a'].size() == 0){
            cout << -1 << endl;
            return;
        }
        
        auto it = lower_bound(v[i - 'a'].begin() , v[i - 'a'].end(), curr);

        if(it != v[i - 'a'].end()){
            curr = *it + 1;
            if(curr == s.size()) {
                if(ind != t.size() - 1) ans++;
                curr = 0;
            }
        }
        else{
            curr = *lower_bound(v[i - 'a'].begin() , v[i - 'a'].end(), 0) + 1;
            ans++;
        }

        ind++;
    }


    cout << ans << nl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}
