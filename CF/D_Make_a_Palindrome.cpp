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
    int n, k;
    cin >> n >> k;
    vector<int> v(n) ,s;
    inp(v)
    s = v;
    sort(all(s));

    int x = s[k-1];

    debug(x);

    s.resize(0);
    debug(s);

    for(int i = 0; i < n; i++){
        if(v[i] < x) s.pb(v[i]);
        else if(v[i] == x) s.pb(-1);
    }

    debug(s);

    int l = 0;
    int r = s.size() - 1;

    int cnt = s.size();
    debug(cnt);

    while(l <= r){
        if(s[l] == s[r]) l++,r--;
        else{
            if(s[l] == -1 || s[r] == -1){
                if(s[l] == -1) l++,cnt--;
                else r--,cnt--;
                if(cnt < k-1){
                    cout << "NO\n";
                    return;
                }
            }
            else {
                cout << "NO\n";
                return;
            }
        }
        debug(l,r,cnt);
    }

    if(cnt < k-1) cout << "NO";
    else cout << "YES";

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