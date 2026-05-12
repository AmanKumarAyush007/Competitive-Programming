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
    int n;
    cin >> n;

    map<int,int> mp;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        mp[x]++;
    }

    int cnt = 0;
    int tot = 0;


    for(auto &[a,b] : mp){
        tot += a * (b - (b%2));
        cnt += (b - (b%2));
        b = b%2;
    }

    vector<int> rem;
    for(auto &[a,b] : mp) if(b) rem.pb(a);


    if(rem.size() == 1){
        if(tot > rem[0]){
            cnt++;
            tot += rem[0];
        }
    }
    else if(rem.size() > 1){
        reverse(all(rem));

        bool taken = 0;
        for(int i = 0; i < rem.size() - 1; i++){
            if(rem[i] - rem[i+1] < tot){
                tot += rem[i] + rem[i+1];
                taken = 1;
                cnt += 2;
                break;
            }
        }
        if(!taken){
            for(int i = 0; i < rem.size(); i++){
                if(rem[i] < tot){
                    tot += rem[i];
                    cnt++;
                    break;
                }
            }
        }
    }

    if(cnt > 2) cout << tot << nl;
    else cout << 0 << nl;
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