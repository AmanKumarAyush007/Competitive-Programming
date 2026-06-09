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
#define inf              (int)1e17
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

    vector<int> a(n), c(n);
    inp(a); inp(c);

    vector<int> temp = c;
    sort(all(temp));

    if((a[0] != c[0] && s[0] == '1') || temp != c) cout << "No";
    else{
        vector<int> bt(n, -inf);

        bt[0] = c[0];

        for(int i = 1; i < n; i++){
            if(c[i] > c[i-1]) bt[i] = c[i];
        }


        for(int i = 1; i < n; i++){
            if(s[i] == '1'){
                bt[i] = max(bt[i-1] + a[i], bt[i]);
                c[i] = min(c[i-1] + a[i], c[i]);
            }
        }

        for(int i = n-1; i > 0; i--){
            if(s[i] == '1'){
                bt[i-1] = max(bt[i] - a[i], bt[i-1]);
                c[i-1] = min(c[i] - a[i], c[i-1]);
            }
        }

        for(int i = 0; i < n; i++){
            if(bt[i] > c[i]){
                cout << "No\n";
                return;
            }
        }

        
        vector<int> b(n);
        b[0] = c[0];

        for(int i = 1; i < n; i++){
            if(s[i] == '1') b[i] = b[i-1] + a[i];
            else b[i] = c[i];
        }
        
        vector<int> ans(n);
        ans[0] = b[0];

        for(int i = 1; i < n; i++){
            ans[i] = b[i] - b[i-1];
        }

        cout << "Yes\n";
        for(auto &i : ans) cout << i << " ";
    }

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

