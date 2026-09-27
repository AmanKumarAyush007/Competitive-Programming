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
    string s;
    cin >> s;
    
    if(is_sorted(all(s))){
        cout << 0 << nl;
        return;
    }

    vector<int> prez(n), preo(n), suffo(n), suffz(n);
    
    for(int i = 0; i < n; i++){
        if(s[i] == '0'){
            prez[i]++;
            suffz[i]++;
        }
        else{
            preo[i]++;
            suffo[i]++;
        } 
    }

    prefixsum(prez);
    prefixsum(preo);
    suffixsum(suffo);
    suffixsum(suffz);


    if(s[0] == '1'){
        cout << suffz[0] << nl;
        return;        
    }




    int ans = inf;
    bool occ = 0;

    for(int i = 0; i < n; i++){
        if(s[i] == '1' && !occ) {
            occ = 1;
            ans = min(ans, suffz[i]);
        }



        if(!occ) ans = min(ans,suffo[i]);   // 1 to 0
        else{
            int l = preo[i];
            int r = (i+1 < n ? min(suffz[i+1], suffo[i+1]) : 0);


            ans = min(ans, l+r);

        }
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