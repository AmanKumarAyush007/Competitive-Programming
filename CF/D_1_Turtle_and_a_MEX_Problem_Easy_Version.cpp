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
    int m;
    cin >> m;
    int mx = 0;
    for(int i = 0; i < n; i++){
        int l;
        cin >> l;
        set<int> st;
        for(int j = 0; j <= l+1; j++) st.insert(j);
        for(int j = 0; j < l; j++){
            int x;
            cin >> x;
            if(st.find(x) != st.end()) st.erase(x);
        }

        int cnt = 0;
        int curr = 0;
        for(int j = 0; j <= l+1; j++){
            if(st.find(j) != st.end()) cnt++;
            if(cnt > 1){
                mx = max(mx,j);
                curr = j;`
                break;
            }
        }
    }

    auto fun = [&](int n){
        return (n*(n+1))/2;
    };


    int ans = 0;
    if(mx < m){
        ans = mx*(mx+1);
        ans += fun(m) - fun(mx);
    }
    else{
        ans = mx*(m+1);
    }

    
    cout<< ans << nl;
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