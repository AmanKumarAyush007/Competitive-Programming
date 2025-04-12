#include<bits/stdc++.h>
using namespace std;

#define int        int64_t
#define ff         first
#define ss         second
#define pb         push_back
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()
#define inp(v)     for(auto& x : v) cin >> x
#define sm(v)      accumulate(all(v),0LL)


void solve(){
    int n,k;
    cin >> n >> k;
    int a[n];
    inp(a);
    map<int,vector<int>> mp;
    for(int i = 1; i <= k; i++){
        mp[i].pb(-1);
    }
    for(int i = 0; i < n; i++){
        mp[a[i]].pb(i);
    }
    for(int i = 1; i <= k; i++){
        mp[i].pb(n);
    }
    int ans = INT_MAX;

    for(auto &[x,v] : mp){
        int dis = 0;
        map<int,int> cnt;
        int mx = -1;
        for(int i = 0; i < v.size()-1; i++){
            if(v[i]+1==v[i+1]) continue;
            cnt[v[i+1] - v[i]-1]++;
            mx = max(mx,v[i+1] - v[i]-1);
        }
        cnt[mx]--;
        cnt[mx/2]++;
        for(auto &[a,b] : cnt){
            if(b) dis = max(dis,a);
        }
        
        ans = min(dis,ans);
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