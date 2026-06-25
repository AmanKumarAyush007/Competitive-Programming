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
#define lg(x)            (63 - __builtin_clzll(x))
#define prefixsum(a)     partial_sum(all(a), (a).begin());
#define suffixsum(a)     partial_sum(rall(a), (a).rbegin());

void solve(){
    int n;
    cin >> n;

    vector<int> v(n);
    inp(v);

    unordered_map<int,int> fre;
    fre.reserve(n * 70);

    for(auto &i : v){
        int x = i;

        unordered_set<int> st;
        st.reserve(70);

        while(true){
            if(x & 1){
                if(st.insert(x).second) fre[x]++;
                if(st.insert(x + 1).second) fre[x + 1]++;
            }
            else{
                if(st.insert(x).second) fre[x]++;
            }

            if(x == 1) break;

            if(x & 1) x++;
            x >>= 1;
        }
    }

    vector<int> val;
    for(auto &[x,y] : fre)
        if(y == n)
            val.pb(x);

    int ans = inf;

    for(auto &q : val){

        int cal = 0;

        for(auto &i : v){
            int x = i;

            while(q < x){
                if(x & 1){
                    cal++;
                    x++;
                }
                x >>= 1;
                cal++;

                if(cal >= ans) break;
            }

            if(cal >= ans) break;

            if(x < q) cal++;
        }

        ans = min(ans, cal);
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