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


    vector<int> pre(n);
        
    for(int i = 0; i < n; i++){
        pre[i] = (s[i] == '1' ? 1 : -1);
    }

    prefixsum(pre);

    //calculate only the numbers of not beautiful substring
    //1 -> pre[l...r] % 3 == 0; => (pre[r] - pre[l-1]) % 3 == 0
    //2 -> odd len alternating substring


    int cnt = 0;

    auto mod = [&](int x){
        x %= 3;
        return x + (x < 0 ? 3 : 0);
    };

    map<int,int> fre;

    for(int i = 0; i < n; i++){
        int curr = mod(pre[i]);
        cnt += fre[curr];
        if(curr == 0) cnt++;
        fre[curr]++;              
    }

    char prec = '#';
    int y = 0;

    for(char c : s){
        if(c == prec) y = 1;
        else y++;

        prec = c;

        cnt += (y - 1) / 2;
    }


    cout << n*(n+1)/2 - cnt << nl;
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