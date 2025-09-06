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
    vector<int> v(n);
    inp(v)
    
    int ans = 0;

    m--;

    if(m != 0&& v[m] > 0){
        v[m] *= -1;
        ans++;
    }

    vector<int> preR = v;
    vector<int> preL = v;

    prefixsum(preR);
    prefixsum(preL);


    priority_queue<int> pq;

    for(int i = m-1; i >= 0 ; i--){
        while(preL[i] < preL[m]){
            preL[m] -= 2*pq.top();
            pq.pop();
            ans++;
        }
        if(v[i] > 0) pq.push(v[i]);
    }

    while (!pq.empty()) {
        pq.pop();
    }

    for(int i = m+1; i < n; i++){
        if(v[i] < 0) pq.push(-v[i]);
        while(preR[i] < preR[m]){
            preR[m] -= 2*pq.top();
            pq.pop();
            ans++;
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