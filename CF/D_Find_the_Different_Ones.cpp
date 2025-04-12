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
    int n; cin >> n;
    int a[n];
    inp(a);
    
    vector<int> v(n);
    v[0] = 1;
    int k = 1;

    for(int i = 1; i < n; i++){
        if(a[i] != a[i-1]) k++;
        v[i] = k;
    }

    int m; cin >> m;

    while(m--){
        int x,y;
        cin >> x >> y;
        x--,y--;
        if(v[x] == v[y]){
            cout << -1 << " " << -1 << nl;
        }
        else{
            auto it = upper_bound(all(v),(v[y]-1));
            cout << (it - v.begin() - 1) + 1  << " " << y+1 << nl;
        }
    }

    // for(auto &i : v) cout << i << " "; 
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