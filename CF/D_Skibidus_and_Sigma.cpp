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
    int n,m;
    cin >> n >> m;
    vector<vector<int>> v(n,vector<int>(m));
    for(auto &vi : v){
        for(auto &i : vi) cin >> i;
    }

    vector<pair<int,int>> vp;
    for(int i = 0; i < n; i++){
        vector<int> temp = v[i];
        int sum = sm(temp);
        vp.pb({sum,i});
    }
    sort(all(vp),greater<pair<int,int>>());
    vector<int> ans;

    int ele = 0;
    for(auto &[a,b] : vp){
        for(int j = 0; j < m; j++){
            ele += v[b][j];
            ans.pb(ele);
        }        
    }


    cout << sm(ans) << nl;
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