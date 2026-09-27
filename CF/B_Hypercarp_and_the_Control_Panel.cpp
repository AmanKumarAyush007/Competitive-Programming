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
    vector<int> v(n);
    inp(v);

    int ans = 0;


    for(int i = 0; i < n; i++){
        if(i > 0 && v[i] == v[i-1]){
            continue;
        }
        ans++;
    }


    vector<int> blc;

    int cnt = 1;
    for (int i = 1; i < n; i++) {
        if (v[i] == v[i - 1])
            cnt++;
        else {
            blc.push_back(cnt);
            cnt = 1;
        }
    }
    blc.push_back(cnt);

    for(int i = 0; i < blc.size() - 1; i++){
        if(blc[i] >= 2 && blc[i+1] >= 2){
            ans += 2;
            cout << ans << nl;
            return;
        }
    }

    // debug(ans);


    int i = 0;
    int j = 0;

    while(i < n){
        while(j+1 < n && v[j+1] == v[i]) j++;

        // debug(i,j);

        if(j-i+1 >= 2){
            if(i-1 >= 0){
                if((i-2 >= 0 && v[i-2] != v[i]) || (i-2 < 0)) {
                    ans++;
                    cout << ans << nl;
                    return;
                }
            }
            if(j+1 < n){
                if((j+2 < n && v[j+2] != v[i]) || (j+2 >= n)) {
                    ans++;
                    cout << ans << nl;
                    return;
                }
            }
        }
        

        // debug(i,j);

        j++;
        i = j;
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