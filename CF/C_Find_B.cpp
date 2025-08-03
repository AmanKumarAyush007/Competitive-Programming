#include<bits/stdc++.h>
using namespace std;

#define int        int64_t
#define ff         first
#define ss         second
#define pb         push_back
#define inf        LLONG_MAX
#define hell       LLONG_MIN
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()
#define sm(v)      accumulate(all(v),0LL)
#define inp(v)     for(auto& x : v) cin >> x;
#define setbit(x)  __builtin_popcountll(x)
#define lg(x)      (63 - __builtin_clzll(x)) //log base 2


#ifndef ONLINE_JUDGE
#include "debug.h" 
#else
  #define debug(x...)
#endif

void solve(){
    int n;
    cin >> n;
    int k;
    cin >> k;
    vector<int> v(n);
    inp(v)
    
    vector<int> pre(n);

    pre[0] = (v[0] == 1);
    for(int i = 1; i < n; i++){
        pre[i] = pre[i-1] + (v[i] == 1);
    }

    vector<int> extra(n);
    for(int i = 0; i < n; i++){
        extra[i] = v[i] - 1;
    }

    for(int i = 1; i < n; i++){
        extra[i] += extra[i-1];
    }
    
    // debug(pre);
    while(k--){
        int l,r;
        cin >> l >> r;

        l--;
        r--;

        if((r-l + 1) == 1) cout << "NO";
        else{
            int cnt1 = pre[r];
            if(l != 0) cnt1 -= pre[l-1];

            int ex = extra[r];
            if(l != 0) ex -= extra[l-1];


            if(cnt1 > ex) cout << "NO";
            else cout << "YES";
        }
        cout << nl;
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