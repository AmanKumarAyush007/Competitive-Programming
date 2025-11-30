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
#define all(a)           (a).begin(), (a).end()
#define rall(a)          (a).rbegin(), (a).rend()
#define sm(v)            accumulate(all(v),0LL)
#define inp(v)           for(auto &x:v) cin>>x;
#define setbit(x)        __builtin_popcountll(x)
#define lg(x)            (63-__builtin_clzll(x))
#define prefixsum(a)     partial_sum(all(a),(a).begin());
#define suffixsum(a)     partial_sum(rall(a),(a).rbegin());

void solve(){
    int n,k; 
    cin>>n>>k;
    vector<int> a(n); 
    inp(a);

    map<int,int> tot;
    for(auto &x:a) tot[x]++;

    for(auto &p:tot){
        if(p.ss % k){
            cout << 0 << nl;
            return;
        }
    }

    map<int,int> tar;
    for(auto &p:tot) tar[p.ff]=p.ss/k;

    map<int,int> win;
    int r=-1, ans=0;

    for(int l=0;l<n;l++){
        if(l>0) win[a[l-1]]--;

        while(r+1<n && win[a[r+1]]+1<=tar[a[r+1]]){
            r++;
            win[a[r]]++;
        }

        if(r>=l) ans+=r-l+1;
    }

    cout << ans << nl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin>>t;
    while(t--) solve();
}
