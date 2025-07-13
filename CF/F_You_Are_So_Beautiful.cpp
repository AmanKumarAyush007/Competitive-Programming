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


void solve(){
    int n;
    cin >> n;
    vector<int> v(n), pre(n), post(n);
    inp(v)
    map<int,int> mp;

    for(int i = 0; i < n; i++){
        mp[v[i]]++;
        pre[i] = mp[v[i]];
        if(mp[v[i]] > 1) pre[i] = 0;
    }

    mp.clear();

    for(int i = n-1; i >= 0; i--){
        mp[v[i]]++;
        post[i] = mp[v[i]];
        if(mp[v[i]] > 1) post[i] = 0;
        if(i < n-1) post[i] += post[i+1]; 
    }

    int ans = 0;

    for(int i = 0; i < n; i++){
        ans += pre[i]*post[i];
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