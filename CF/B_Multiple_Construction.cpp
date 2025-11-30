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
    int n;
    cin >> n;
    vector<int> v((2*n)+1);

    set<int> s;
    for(int i = 1; i <= 2*n; i++){
        s.insert(i);
    }

    int curr = n;
    for(int i = 1; i <= n; i += 2){
        s.erase(i);
        s.erase(i + curr);
        v[i] = curr;
        v[i+curr] = curr;
        curr--;
    }

    while(curr > 0 && !s.empty()){
        bool paired = false;
        int small = *s.begin();

        for(auto rit = s.rbegin(); rit != s.rend(); ++rit){
            int big = *rit;
            if(big == small) continue; 
            if((big - small) % curr == 0){
                v[big] = curr;
                v[small] = curr;
                s.erase(big);
                s.erase(small);
                curr--;
                paired = true;
                break;
            }
        }

        if(!paired){
            break;
        }
    }

    for(int i = 1; i <= 2*n; i++){
        cout << v[i] << " ";
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