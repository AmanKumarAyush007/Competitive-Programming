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
    int n;
    cin >> n;
    vector<int> a(n), b(n), c,d;
    inp(a);
    inp(b);

    c = a, d = b;

    sort(all(c)), sort(all(d));

    vector<pair<int,int>> ans;

    for(int i = 0; i < n; i++){
        int X = c[i];
        int Y = d[i];
        int ind = -1;

        for(int j = i; j < n; j++){
            if(a[j] == X && b[j] == Y){
                swap(a[i],a[j]);
                swap(b[i],b[j]);
                ind = j;
                break;
            }
        }

        if(ind == -1){
            cout << -1 << nl;
            return;
        }
        else if(ind != i){
            ans.pb({ind+1,i+1});
        }
    }

    cout << ans.size() << nl;
    for(auto &[a,b] : ans) cout << a << " " << b << nl;
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