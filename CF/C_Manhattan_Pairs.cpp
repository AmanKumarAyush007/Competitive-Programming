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
#define ppi          pair<pair<int, int>, int>

#ifndef ONLINE_JUDGE
#include "debug.h" 
#else
  #define debug(x...)
#endif


int tot(vector<ppi>& a, vector<ppi>& b) {
    int dis = 0;
    for (int i = 0; i < a.size(); ++i) {
        dis += abs(a[i].ff.ff - b[i].ff.ff) + abs(a[i].ff.ss - b[i].ff.ss);
    }
    return dis;
}

void solve(){
    int n;
    cin >> n;

    vector<ppi> vpp(n);
    for(int i = 0; i < n; ++i){
        cin >> vpp[i].ff.ff >> vpp[i].ff.ss;
        vpp[i].ss = i + 1; 
    }


    

    vector<ppi> pointsX = vpp;
    sort(all(pointsX), []( ppi& a,  ppi& b) {
        return a.ff.ff < b.ff.ff;
    });

    vector<ppi> aX, bX;
    for(int i = 0; i < n / 2; ++i) aX.pb(pointsX[i]);
    for(int i = n / 2; i < n; ++i) bX.pb(pointsX[i]);
    
    sort(all(aX), []( ppi& a,  ppi& b) { return a.ff.ss < b.ff.ss; });
    sort(all(bX), []( ppi& a,  ppi& b) { return a.ff.ss > b.ff.ss; });
    
    int OpX = tot(aX, bX);



    vector<ppi> pointsY = vpp;
    sort(all(pointsY), []( ppi& a,  ppi& b) {
        return a.ff.ss < b.ff.ss;
    });

    vector<ppi> aY, bY;
    for(int i = 0; i < n / 2; ++i) aY.pb(pointsY[i]);
    for(int i = n / 2; i < n; ++i) bY.pb(pointsY[i]);

    sort(all(aY), []( ppi& a,  ppi& b) { return a.ff.ff < b.ff.ff; });
    sort(all(bY), []( ppi& a,  ppi& b) { return a.ff.ff > b.ff.ff; });
    
    int OpY = tot(aY, bY);




    if (OpX >= OpY) {
        for (int i = 0; i < n / 2; ++i) {
            cout << aX[i].ss << " " << bX[i].ss << nl;
        }
    } else {
        for (int i = 0; i < n / 2; ++i) {
            cout << aY[i].ss << " " << bY[i].ss << nl;
        }
    }
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
