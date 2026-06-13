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
    
    vector<int> v(n);
    inp(v);

    vector<int> od, ev;

    for(auto &i : v){
        if(i&1) od.pb(i);
        else ev.pb(i);
    }

    int mxod = -inf, mxev = -inf;
    int mnod = inf, mnev = inf;

    for(auto &i : od) {
        mxod = max(mxod, i);
        mnod = min(mnod, i);
    }

    for(auto &i : ev) {
        mxev = max(mxev, i);
        mnev = min(mnev, i);
    }

    bool check = true;

    if(ev.size()){
        int currmx = ev[0];

        for(int i = 1; i < ev.size(); i++){
            if(ev[i] >= currmx){
                currmx = ev[i];
            }
            else{
                if(mnod < currmx && mnod < ev[i]) continue;
                if(mxod > currmx && mxod > ev[i]) continue;

                check = false;
                break;
            }
        }
    }


    if(od.size()){
        int currmx = od[0];

        for(int i = 1; i < od.size(); i++){
            if(od[i] >= currmx){
                currmx = od[i];
            }
            else{
                if(mnev < currmx && mnev < od[i]) continue;
                if(mxev > currmx && mxev > od[i]) continue;

                check = false;
                break;
            }
        }
    }



    cout << (check ? "YES" : "NO") << nl;
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