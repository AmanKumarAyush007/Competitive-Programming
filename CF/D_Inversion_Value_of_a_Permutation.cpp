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

const int N = (30*29)/2 + 5;

vector<vector<int>> para(N);
vector<int> tot(N, inf);

void precompute(){
    tot[0] = 0;

    vector<pair<int,int>> vp;
    for(int i = 1; ; i++){
        int seg = i*(i-1)/2;
        if(seg >= N) break;
        vp.pb({i,seg});
    }

    for(int i = 1; i < N; i++){
        for(auto &[len, seg] : vp){
            if(i >= seg && tot[i-seg] != inf){
                if(tot[i-seg] + len < tot[i]){
                    tot[i] = tot[i-seg] + len;
                    para[i] = para[i-seg];
                    para[i].pb(len);
                }
            }
        }
    }

}

void solve(){
    int n,k;
    cin >> n >> k;

    int sub = n*(n-1)/2;

    int req = sub - k;

    if(tot[req] > n) cout << 0 << nl;
    else{
        int curren = n;
        int currst = 1;

        for(int i = 0; i < para[req].size(); i++){
            currst = curren - para[req][i] + 1;
            for(int j = currst; j <= curren; j++){
                cout << j << " ";
            }
            curren = currst - 1;
        }

        while(curren > 0){
            cout << curren << " " ;
            curren--;
        }
    }
    cout << nl;
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