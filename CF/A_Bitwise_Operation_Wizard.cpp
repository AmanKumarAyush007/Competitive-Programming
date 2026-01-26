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
#define nl               endl
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

    auto query = [&](int a, int b, int c, int d){
        cout << "? ";
        cout << a << " " << b << " " << c << " " << d << nl;
        char ch;
        cin >> ch;
        return ch;
    };


    int mx = 0;
    
    for(int i = 1; i < n; i++){
        char res = query(mx,mx,i,i);
        if(res == '<'){
            mx = i;
        }
    }

    vector<int> vp;
    int ind = 0;

    for(int i = 0; i < n; i++){
        char res = query(ind,mx,i,mx);
        if(res == '='){
            vp.pb({i});
        }
        else if(res == '<'){
            vp.clear();
            ind = i;
            vp.pb({ind});
        }
    }


    int mn = vp[0];

    for(int i = 1; i < vp.size(); i++){
        int x = vp[i];
        char res = query(mn,mn,x,x);
        if(res == '>'){
            mn = x;
        }
    }


    cout << "! " << mn << " " << mx;
    
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