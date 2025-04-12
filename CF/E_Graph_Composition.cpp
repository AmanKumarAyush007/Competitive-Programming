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
    int n,x,y;
    cin >> n >> x >> y;
    map<pair<int,int>,int> f,g;

    while(x--){
        int a,b;
        cin >> a >> b;
        if(a > b) swap(a,b);
        f[make_pair(a,b)]++;
    }

    while(y--){
        int a,b;
        cin >> a >> b;
        if(a > b) swap(a,b);
        g[make_pair(a,b)]++;
    }
    int ans = 0;

    // for(auto &[a,b] : g){
    //     auto it = f.find(a); 
    //     if (it == f.end()) {
    //         ans++;  
    //     } else {
    //         f.erase(it); 
    //     }
    // }

    for(auto &[a,b] : f){
        auto it = g.find(a);
        if(it == g.end()) ans++;
        else {
            g.erase(it); 
        }
    }



    // cout << ans + f.size();
    cout << ans + g.size();


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