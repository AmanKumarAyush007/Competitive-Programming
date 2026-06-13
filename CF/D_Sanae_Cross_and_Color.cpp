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
    
    vector<int> px(n), py(n);
    for(int i = 0; i < n; i++) cin >> px[i] >> py[i];
    
    vector<int> idx(n);
    iota(all(idx), 0);
    sort(all(idx), [&](int a, int b){ return px[a] < px[b]; });
    
    vector<int> vy(py.begin(), py.end());
    sort(all(vy));
    vy.erase(unique(all(vy)), vy.end());
    
    vector<int> hiArr, loArr;
    hiArr.reserve(n); loArr.reserve(n);
    
    int i = 0;
    while(i < n){
        int j = i;
        int curX = px[idx[i]];
        int lo = py[idx[i]], hi = py[idx[i]];
        while(j < n && px[idx[j]] == curX){
            lo = min(lo, py[idx[j]]);
            hi = max(hi, py[idx[j]]);
            j++;
        }
        loArr.pb(lo);
        hiArr.pb(hi);
        i = j;
    }
    
    int m = (int)hiArr.size();
    
    vector<int> prehi(m), prelo(m), posthi(m), postlo(m);
    prehi[0] = hiArr[0]; prelo[0] = loArr[0];
    for(int i = 1; i < m; i++){
        prehi[i] = max(prehi[i-1], hiArr[i]);
        prelo[i] = min(prelo[i-1], loArr[i]);
    }
    posthi[m-1] = hiArr[m-1]; postlo[m-1] = loArr[m-1];
    for(int i = m-2; i >= 0; i--){
        posthi[i] = max(posthi[i+1], hiArr[i]);
        postlo[i] = min(postlo[i+1], loArr[i]);
    }
    
    int ans = 0;
    for(int i = 0; i < m-1; i++){
        int hi = min(prehi[i], posthi[i+1]);
        int lo = max(prelo[i], postlo[i+1]);
        if(hi > lo){
            auto itl = lower_bound(all(vy), lo);
            auto itr = lower_bound(all(vy), hi);
            ans += (int)(itr - itl);
        }
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