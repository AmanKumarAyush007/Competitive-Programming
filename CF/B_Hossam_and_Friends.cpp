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
    int n,m;
    cin >> n >> m;

    map<int,int> mp;

    for(int i = 1; i <= n; i++){
        mp[i] = n+1;
    }

    for(int i = 0; i < m; i++){
        int x,y;
        cin >> x >> y;
        if(x > y) swap(x,y);
        mp[x] = min(y,mp[x]);
    }


    int sum = 0;

    for(int i = n-1; i >= 0; i--){
        mp[i] = min(mp[i],mp[i+1]);
    }

    for(int i = 1; i <= n; i++){
        sum += mp[i] - i;
    }
    
    cout << sum << nl;
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