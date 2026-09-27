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

    if(s[0] == '0' || s.find("00") != string::npos){
        cout << -1 << nl;
        return;
    }

    int x = count(all(s),'+');
    int y = count(all(s),'-');

    if(x == n || y == n){
        cout << 1 << nl;
        return;
    }

    bool turn = 1;

    vector<int> pre(n);
    for(int i = n-1; i >= 0; i--){
        if(s[i] == '0') pre[i] = 0;
        else if(i == n-1) pre[i] = (s[i] == '+' ? 1 : -1);
        else {
            if(s[i] == s[i+1]){
                if(turn) {
                    pre[i] = (s[i] == '+' ? pre[i+1]+1 : pre[i+1]-1);
                }
                else{
                    pre[i] = (s[i] == '-' ? pre[i+1]+1 : pre[i+1]-1);
                    
                } 
                turn = !turn;
            }
            else{
                turn = 1;
                pre[i] = (s[i] == '+' ? 1 : -1);
            }
        }
    }

    // debug(pre);

    vector<int> a(n);
    a[0] = pre[0];

    for(int i = 1; i < n; i++){
        a[i] = pre[i] - pre[i-1];
    }

    int ans = -inf;

    for(auto &i : a) ans = max(abs(i), ans);

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