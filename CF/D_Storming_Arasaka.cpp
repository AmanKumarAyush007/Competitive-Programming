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


const int N = 1e6 + 7;
vector<int> spf(N,-1);
vector<vector<pair<int,int>>> fact(N); 

void precompute(){
    for(int i = 2; i < N; i++){
        if(spf[i] == -1){
            spf[i] = i;
            for(int j = i*i; j < N; j += i){
                if(spf[j] == -1) spf[j] = i;
            }
        }
    }

    for(int i = 2; i < N; i++){
        int x = i;
        while(x > 1){
            int y = spf[x];
            int cnt = 0;
            while(x%y == 0) {
                x /= y;
                cnt++;
            }
            fact[i].pb({y,cnt});
        }
    }
}

void solve(){
    int n;
    cin >> n;

    int ans = fact[n].size();

    for(auto &[x,y] : fact[n]) ans += y;
    ans--;
    
    cout << ans << nl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    precompute();

    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}