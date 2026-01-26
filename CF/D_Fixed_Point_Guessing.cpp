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

    auto query = [&](int l, int r){
        cout << "? " << l << " " << r << nl;

        int cnt = 0;

        for(int i = l; i <= r; i++){
            int x;
            cin >> x;
            if(x <= r && x >= l) cnt++;
        }

        return (cnt%2);
    };

    int l = 1, r = n;

    bool found = true;

    while(l != r){
        int mid = (l+r)/2;

        if(query(l,mid)){
            r = mid;
        }
        else l = mid + 1;
    }

    cout << "! " << l;
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



// 4,2,5,1,3