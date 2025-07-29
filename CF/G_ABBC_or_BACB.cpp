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

#ifndef ONLINE_JUDGE
#include "debug.h" 
#else
  #define debug(x...)
#endif

void solve(){
    string s;
    cin >> s;
    int n = s.size();
    int ans = 0;


    vector<int> pre(n), post(n);

    if(s[0] == 'A') pre[0] = 1;
    for(int i = 1; i < n; i++){
        if(s[i] == 'B') pre[i] = 0;
        else pre[i] = pre[i-1] + 1;
    }

    if(s[n-1] == 'A') post[n-1] = 1;
    for(int i = n-2; i >= 0; i--){
        if(s[i] == 'B') post[i] = 0;
        else post[i] = post[i+1] + 1;
    }
    

    vector<int> ind;
    
    for(int i = 0; i < n; i++){
        if(s[i] == 'B') ind.pb(i);
    }

    
    if(ind.size() == 0) ans = 0;
    else if(ind.size() == 1){
        int x = ind[0] - 1;
        int y = ind[0] + 1;
        if(x >= 0) ans = max(pre[x],ans);
        if(y < n) ans = max(ans,post[y]);
    }
    else{
        vector<int> cnt;


        for(int i = 0; i < ind.size(); i++){
            int x = ind[i] - 1;
            if(x >= 0) cnt.pb(pre[x]);
        }
        int y = ind[ind.size() - 1] + 1;
        if(y < n) cnt.pb(post[y]);



        sort(all(cnt));

        ans += sm(cnt);
        if(cnt.size() > ind.size()) ans -= cnt[0];
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