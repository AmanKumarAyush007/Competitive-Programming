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

set<pair<int,int>> adj;

int ask(int x, int y){
    cout << "? " << x << " " << y << nl;
    int res;
    cin >> res;
    return res;
}

void rec(int x, int y){
    int mid = ask(x,y);

    if(mid == x) {
        adj.insert({x,y});
        return;
    }

    rec(mid,y);
}

void solve(){
    int n;
    cin >> n;

    vector<pair<int,int>> v;
    adj.clear();

    for(int i = 2; i <= n; i++){
        rec(1,i);
    }

    cout << "! ";
    for(auto &[a,b] : adj) cout << a << " " << b << " ";
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