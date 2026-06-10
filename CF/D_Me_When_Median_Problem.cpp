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
    vector<int> a(n), b(n);
    inp(a); inp(b);

    auto check = [&](int x){
        vector<int> bin(n, -2);
        for(int i = 0; i < n; i++){
            if(a[i] >= x && b[i] >= x) bin[i] = 1;
            else if(a[i] < x && b[i] < x) bin[i] = -1;
            else bin[i] = 0;
        }

        int pos = 0, zero = 0;

        for(int i = 0; i < n; i++){
            if(bin[i] == 0) zero++;
            else if(bin[i] == 1) pos++;
            else{
                pos--;
                int ind = i;
                while(ind + 1 < n && bin[ind+1] != 1) ind++;
                i = ind;
            }
        }

        return pos > 0;
    };
    

    int lo = 0, hi = 2*n + 5;
    int ans = 0;

    while(lo <= hi){
        int mid = (lo+hi)/2;

        if(check(mid)) {
            lo = mid + 1;
            ans = mid;
        }
        else hi = mid - 1;    
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