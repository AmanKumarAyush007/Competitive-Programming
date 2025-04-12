#include<bits/stdc++.h>
using namespace std;

#define int        int64_t
#define ff         first
#define ss         second
#define pb         push_back
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()
#define inp(v)     for(auto& x : v) cin >> x


void solve(){ 
    int n,m;
    cin >> n >> m;
    
    vector<int> v(1e9 + 9);
    for(int i = 1; i <= m; i++){
        v[i] = (n^i);
    }
    int ans = 0;
    for(int i = 1; i <= 1e9; i++){
        if(i<=m && i != m && i)
    }
    
    cout << nl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}