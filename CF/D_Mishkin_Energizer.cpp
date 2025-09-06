#include<bits/stdc++.h>
using namespace std;

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


#ifndef ONLINE_JUDGE
#include "debug.h" 
#else
  #define debug(x...)
#endif

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    map<char,int> mp;
    for(auto &i : s) mp[i]++;

    if(mp.size() == 1) cout << -1 << nl;
    else if(mp['L'] == mp['I'] && mp['I'] == mp['T']) cout << 0 << nl;
    else{
        vector<int> ans;

        int curr = 0;
        int i = 0;

        int zz = 1;

        while(i < n-1){
            int cont = 1;
            while(i < n-1 && s[i] == s[i+1]){
                cont++;
                i++;
            }
            // if(cont == 1) i++;
            if(i == n-1){
                zz = cont;
                continue;
            }

            debug(cont,i);


            curr += cont;

            int ad = cont * 2;

            while(ad--){
                ans.pb(curr);
            }

            curr += cont * 2;
            i++;
        }

        debug(zz);
        int st = 3*(n - zz);
        zz *= 2;
        while(zz--) ans.pb(st++);

        cout << ans.size() << nl;
        for(auto &i : ans) cout << i << "\n";
    }
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