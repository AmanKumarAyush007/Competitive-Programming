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
#define nl               endl
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

    vector<int> ans(2*n+1, -1);

    set<int> uni;
    uni.insert(1);

    auto query = [&](int x){
        cout << "? " << " " << uni.size() + 1 << " ";
        for(auto &i : uni) cout << i << " ";
        cout << x  << nl;

        int res;
        cin >> res;

        if(res == 0){
            uni.insert(x);
        }
        else{
            ans[x] = res;
        }

    };

    for(int i = 2; i <= 2*n; i++){
        query(i);
    }

    uni.clear();

    for(int i = 1; i <= 2*n; i++){
        if(ans[i] != -1) uni.insert(i);
    }

    for(int i = 1; i <= 2*n; i++){
        if(ans[i] == -1) query(i);
    }

    cout << "! " << nl;
    for(int i = 1; i <= 2*n; i++){
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