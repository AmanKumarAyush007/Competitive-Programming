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
    int n,m,x,y;
    cin >> n >> m >> x >> y;

    multiset<int> msa, msb;
    for(int i = 0; i < x; i++){
        int ele;
        cin >> ele;
        msa.insert(ele);
    }
    for(int i = 0; i < y; i++){
        int ele;
        cin >> ele;
        msb.insert(ele);
    }


    
    vector<int> comm;
    for(auto &i : msa) if(msb.count(i)) comm.pb(i);
    
    
    for(auto &i : comm){
        msa.erase(i);
        msb.erase(i);
    }

    vector<int> tk;

    while(msa.size()){
        if(tk.size() == n) break;
        auto it = prev(msa.end());
        tk.pb(*it);
        msa.erase(it);
    }



    int sz = tk.size();
    
    while(msb.size()){
        if(tk.size()-sz == m) break;
        auto it = prev(msb.end());
        tk.pb(*it);
        msb.erase(it);
    }


    
    for(auto &i : comm) tk.pb(i);
    
    
    sort(all(tk));
    

    int lim = 0;
    int ans = 0;
    for(int i = tk.size()-1; i >= 0; i--){
        if(lim == n+m-1) break;
        ans += tk[i];
        lim++;
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