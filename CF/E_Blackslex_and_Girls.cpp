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
    int n,x,y;
    cin >> n >> x >> y;

    string s;
    cin >> s;

    vector<int> p(n);
    inp(p);

    int sp = sm(p);

    int cnt1 = 0, cnt0 = 0;

    for(auto &i : s){
        if(i == '0') cnt0++;
        else cnt1++;
    }

    int ar = 0, br = 0;

    for(int i = 0; i < n; i++){
        int need = (p[i]/2) + 1;
        if(s[i]-'0'){
            br += need;
        }
        else ar += need;
    }

    if(sp > x+y || (ar > x) || (br > y)) cout << "NO";
    else if(cnt0 == n && x-y < n) cout << "NO";
    else if(cnt1 == n && y-x < n) cout << "NO";
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