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

const int MAXN = 2e5 + 5;
vector<int> spf(MAXN + 1);

void precompute() {
    for (int i = 1; i < MAXN; i++) spf[i] = i;

    for (int i = 2; i * i < MAXN; i++) {
        if (spf[i] == i) { 
            for (int j = i * i; j < MAXN; j += i) if(spf[j] == j) spf[j] = i;
        }
    }
}


void solve(){
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    inp(a);
    inp(b);

    set<int> s;

    for(int i = 0; i < n; i++){
        int x = a[i];
        set<int> p;
        while(x > 1){
            p.insert(spf[x]);
            x /= spf[x];
        }
        for(auto &j : p){
            if(s.count(j)){
                cout << 0 << nl;
                return;
            }
            s.insert(j);
        }
    }


    for(int i = 0; i < n; i++){
        int x = a[i] + 1;
        set<int> p;
        while(x > 1){
            p.insert(spf[x]);
            x /= spf[x];
        }
        for(auto &j : p){
            if(s.count(j)){
                cout << 1 << nl;
                return;
            }
        }
    }


    cout << 2 << nl;
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