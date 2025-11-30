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
    int n ,k;
    cin >> n >> k;
    string s;
    cin >> s;

    if(count(all(s),'1') == 0){
        cout << 0 << nl;
        return;
    }

    int fo, lo;

    fo = lo = -1;
    int ind = -1;

    for(int i = n-1; i >= 0; i--){
        if(s[i] == '1') {
            ind = i;
            break;
        }
    }

    if(ind != -1) lo = ind;

    ind = -1;
    for(int i = 0; i < n; i++){
        if(s[i] == '1') {
            ind = i;
            break;
        }
    }
    if(ind != -1) fo = ind;

    int ld = n-1 - lo;
    int fd = fo;
    if(count(all(s),'1') == 1){
        if(ld <= k) swap(s[n-1],s[lo]);
        else if (fd <= k) swap(s[0],s[fo]);
    }
    else{
        if(ld + fd <= k){
            swap(s[0],s[fo]);
            swap(s[n-1],s[lo]);
        }
        else if(ld <= k) swap(s[n-1],s[lo]);
        else if (fd <= k) swap(s[0],s[fo]);
    }
    

    int ans = 0;

    for(int i = 0; i < n-1; i++){
        int x = stoi(s.substr(i,2));
        ans += x;
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