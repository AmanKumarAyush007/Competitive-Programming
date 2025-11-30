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

int N = 1e7; 
vector<int> fact(N + 1);

void precompute(){
    fact[0] = 0;
    fact[1] = 1;
    for(int i = 2; i <= N; i++){
        if(!fact[i]){
            fact[i] = i;
            if(i * i <= N){
                for(int j = 1LL * i * i; j <= N; j += i){
                    if(!fact[j]) fact[j] = i;
                }
            }
        }
    }
}

void solve(){
    int n, q;
    cin >> n >> q;

    while(q--){
        int d;
        cin >> d;

        if(d == 1){
            cout << 0 << " " << 1 << nl;
            continue;
        }

        int temp = d;
        vector<pair<int,int>> fac;
        while(temp > 1){
            int p = fact[temp];
            if(p == 0) p = temp;
            int e = 0;
            while(temp % p == 0){
                temp /= p;
                e++;
            }
            fac.pb({p,e});
        }


        int mx = 0;
        int x = 1;
        bool even = true;

        for(auto &[a,b] : fac){
            int e = b;
            mx += e;
            x *= (e + 1);
            if(e % 2) even = false;
        }

        int ans = even ? (x + 1) / 2 : x / 2;
        cout << mx << " " << ans << nl;
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    precompute();

    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}
