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

bool comp (const pair<int,int>& a, const pair<int,int>& b) {
    if(a.ff == b.ff) return a > b;
    return a < b;
}

void solve(){
    int n;
    cin >> n;
    vector<pair<int,int>> vp;
    for(int i = 0; i < n; i++){
        int x,y;
        cin >> x >> y;
        vp.pb({x,1});
        vp.pb({y,-1});
    }
    sort(all(vp),comp);
    int d = 0;
    for(auto &[a,b] : vp){
        d += b;
        if(d > 2){
            cout << "NO\n";
            return;
        }
    }    
    cout << "YES" << nl;
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