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

map<string, string> unlinked;

void solve(){
    int n,m;
    cin >> n >> m;

    map<string, vector<int>> mp;
    vector<string> v(n+1);


    for(int i = 1; i <= n; i++){
        string s;
        cin >> s;
        v[i] = s;
        mp[s].pb(i);
    }


    while(m--){
        int x,y;
        cin >> x >> y;

        if(x > y) swap(x,y);

        if(unlinked[v[x]] != v[y]){
            cout << abs(x-y) << nl;
            continue;
        }

        bool ck = false;

        for(auto &[a,b] : mp){
            if(a != v[x] && a != v[y]){
                auto it = upper_bound(all(b),x);
                if((it != b.end()) && (*it < y)){
                    cout << abs(x-y) << nl;
                    ck = true;
                    break;
                }
            }
        }

        if(ck) continue;

        int ans = -1;

        for(auto &[a,b] : mp){
            if(a != v[x] && a != v[y]){
                auto it = lower_bound(all(b),x);
                if((it != b.begin())){
                    int mid = *prev(it);
                    int val = 2*(abs(mid - x)) + abs(x-y);
                    if(ans != -1) ans = min(ans,val);
                    else ans = val;
                }
            }
        }


        for(auto &[a,b] : mp){
            if(a != v[x] && a != v[y]){
                auto it = upper_bound(all(b),y);
                if(it != b.end()){
                    int mid = *(it);
                    int val = 2*(abs(mid - y)) + abs(x-y);
                    if(ans != -1) ans = min(ans,val);
                    else ans = val;
                }
            }
        }

        cout << ans << nl;
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;

    unlinked["BG"] = "RY";
    unlinked["RY"] = "BG";

    unlinked["BR"] = "GY";
    unlinked["GY"] = "BR";

    unlinked["BY"] = "GR";
    unlinked["GR"] = "BY";

    while(t--){
        solve();
    }
    return 0;
}