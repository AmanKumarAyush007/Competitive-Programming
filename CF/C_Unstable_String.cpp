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
    string s;
    cin >> s;

    int n = s.size();

    vector<pair<int,int>> vp;

    int st = 0;

    for(int i = 0; i < n-1; i++){
        if(s[i] != '?' && s[i] == s[i+1]){
            vp.pb({i,i+1});
        }
    }

    for(int i = 1; i < n-1; i++){
        if(s[i] == '?'){
            int x = i-1;
            while(i+1 < n && s[i] == '?' && s[i] == s[i+1]){
                i++;
            }
            if(i+1 < n){
                int l = i+1 - x + 1;
                if(s[x] != '?' && s[i+1] != '?'){
                    if(l%2){
                        if(s[x] != s[i+1]) vp.pb({x,i+1});
                    }
                    else {
                        if(s[x] == s[i+1]) vp.pb({x,i+1});
                    }
                }
            }
        }
    }

    sort(all(vp));

    auto val = [&](int x){
        return (x*(x+1))/2;
    };


    int ans = 0;

    for(auto &[l,r] : vp){
        int tk = r-1 - st + 1;
        ans += val(tk);
        int ex = r-l-1;
        ans -= val(ex);
        st = l+1;
    }

    int lst = n-1 - st + 1;

    ans += val(lst);

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