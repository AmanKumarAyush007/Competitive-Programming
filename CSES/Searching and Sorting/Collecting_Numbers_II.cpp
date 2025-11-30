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

    vector<int> v(n+1), a(n+1);

    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        a[i] = x;
        v[x] = i;
    }

    int ans = 1;

    for(int i = 1; i < n; i++){
        if(v[i] > v[i+1]) ans++;
    }

    while(m--){
        int i,j;
        cin >> i >> j;

        if(i > j) swap(i,j);

        int x = a[i], y = a[j];

        if(v[x+1] > i && v[x+1] < j) ans++; 
        if(v[x-1] > i && v[x-1] < j) ans--;
        if(v[y+1] > i && v[y+1] < j) ans--;
        if(v[y-1] > i && v[y-1] < j) ans++;

        if(x == (y+1)) ans--;
        if(x == (y-1)) ans++;

        cout << ans << nl;
        
        swap(v[a[i]],v[a[j]]);
        swap(a[i],a[j]);
    }

}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}