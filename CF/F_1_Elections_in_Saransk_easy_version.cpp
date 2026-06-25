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

const int N = 5e5+5;
const int mod = 1e9+7;
vector<int> spf(N+5);
vector<vector<pair<int,int>>> fact(N+5);

void precompute(){
    for(int i = 0; i <= N; i++){
        spf[i] = i;
    }

    for(int i = 2; i*i < N; i++){
        if(spf[i] == i){
            for(int j = i*i; j < N; j += i){
                if(spf[j] == j) spf[j] = i;
            }
        }
    }
 

    for(int i = 2; i < N; i++){
        int x = i;
        while(x > 1){
            int div = spf[x];
            int cnt = 0;
            while(x % div == 0){ 
                cnt++;
                x /= div;
            } 
            fact[i].pb({div,cnt});
        }
    }
}

void solve(){
    int n;
    cin >> n;
    int x;
    cin >> x;

    vector<int> v(n);
    inp(v);

    map<int,int> mp;

    for(auto &i : v){
        if(i == 1) continue;
        for(auto &[x,y] : fact[i]){
            mp[x] += y;
        }
    }

    int ans = 1;
    for(auto &[a,b] : mp) ans *= (1+b), ans %= mod;

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