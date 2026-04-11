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
    int n,m;
    cin >> n >> m;

    multiset<int> a,b;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        a.insert(x);
    }
    for(int i = 0; i < m; i++){
        int x;
        cin >> x;
        b.insert(x);
    }

    bool turn = 1;

    while(true){
        int alst = *prev(a.end());
        int blst = *prev(b.end());
        if(turn&1){
            b.erase(prev(b.end()));
            if(blst > alst){
                b.insert(blst - alst);
            }
        }
        else{
            a.erase(prev(a.end()));
            if(alst > blst){
                a.insert(alst - blst);
            }
        }

        turn ^= 1;

        if(a.size() && b.size()){
            continue;
        }
        else {
            cout << (turn ? "Bob" : "Alice");
            break;
        }
    }


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