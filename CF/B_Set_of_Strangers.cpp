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
    int a[n][m];
    map<int,int> adj;
    
    for(auto &ar : a){
        for(auto &i : ar) {
            cin >> i;
            adj[i] = 1;
        }
    }
    
    if(adj.size() == 1){
        cout << 0 << nl;
        return;
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            
            if(i > 0 && a[i-1][j] == a[i][j]) adj[a[i][j]] = 2;
            else if ((i <= n-2) && (a[i+1][j] == a[i][j])) adj[a[i][j]] = 2;
            else if(j > 0 && (a[i][j-1] == a[i][j])) adj[a[i][j]] = 2;
            else if((j <= m-2) && (a[i][j+1] == a[i][j])) adj[a[i][j]] = 2;
        }
    }

    int ans = 0;
    int mx = -1;
    for(auto &[a,b] : adj){
        ans += b;
        mx = max(mx,b);
    }
    
    cout << ans - mx;
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