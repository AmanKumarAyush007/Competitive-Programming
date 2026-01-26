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

    vector<int> v(n);
    inp(v);

    if(m > n/2) cout << -1 << nl;
    else{
        vector<pair<int,int>> vp(n);
        for(int i = 0; i < n; i++){
            vp[i].ff = v[i];
            vp[i].ss = i;
        }
        
        sort(all(vp));
        
        vector<pair<int,int>> ans;
        
        if(m == 0){
            int curr = 0;

            int mx = vp[n-1].ff;
            int rest = 0;
            for(int i = 0; i < n-1; i++){
                rest += vp[i].ff;
            }

            if(rest < mx){
                cout << -1 << nl;
                return;
            }

            while(curr < n-1 && rest - vp[curr].ff >= mx){
                ans.pb({vp[curr].ss, vp[curr+1].ss});
                rest -= vp[curr].ff;
                curr++;
            }

            while(curr < n-1){
                ans.pb({vp[curr].ss,vp[n-1].ss});
                curr++;
            }
        }
        else{
            
            for(int i = 0; i < m - 1; i++){
                ans.pb({vp[2 * i + 1].ss, vp[2 * i].ss});
            }
            for(int i = 2 * (m - 1); i < n - 1; i++){
                ans.pb({vp[i + 1].ss, vp[i].ss});
            }

        }
        cout << ans.size() << nl;

        for(auto &[a,b] : ans){
            cout << a+1 << " " << b+1 << nl;
        }
    }


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