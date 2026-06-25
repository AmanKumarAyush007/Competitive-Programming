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

    auto prn = [&](int st){
        for(int i = st; i <= n; i++){
            cout << i << " ";
        }
        cout << nl;
    };

    cout << "? " << n << " ";
    prn(1);
    int res;

    cin >> res;

    int op, cl;
    if(res == 0){
        op = n;
        cl = 1;
    }
    else {
        int lo = 1, hi = n,canc = 1;

        while(lo <= hi){
            int mid = (lo+hi)/2;

            cout << "? "<< mid << " ";
            for(int i = 1; i <= mid; i++){
                cout << i << " ";
            }
            cout << nl;

            cin >> res;

            if(res > 0){
                canc = mid;
                hi = mid-1;
            }
            else {
                lo = mid+1;
            }
        }

        op = canc-1;
        cl = canc;
    }

    string ans;


    for(int i = 1; i < n; i += 2){
        vector<int> v;
        v.pb(op);
        v.pb(i);
        v.pb(i+1);
        v.pb(cl);
        v.pb(op);
        v.pb(op);
        v.pb(i);
        v.pb(cl);
        v.pb(i+1);
        v.pb(cl);
        v.pb(cl);

        cout << "? " << v.size() << " ";
        for(auto &el : v) cout << el << " ";
        cout << nl;



        cin >> res;



        if(res == 5){
            ans += "((";
        }
        else if(res == 3) ans += "))";
        else if(res == 6) ans += "()";
        else ans += ")(";
    }


    if(n&1){
        cout << "? " << 2 << " " << n << " " << cl;
        cout << nl;
        cin >> res;
        if(res == 1) ans += "(";
        else ans += ")";
    }

    cout << "! " << ans << nl;
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
