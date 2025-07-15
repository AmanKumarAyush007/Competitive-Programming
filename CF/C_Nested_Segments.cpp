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

#ifndef ONLINE_JUDGE
#include "debug.h" 
#else
  #define debug(x...)
#endif

bool cmp(const pair<pair<int,int>,int>& a, const pair<pair<int,int>,int>& b){
    if(a.ff.ff == b.ff.ff && a.ff.ss != b.ff.ss) return a > b;
    else return a < b;
}

void solve(){
    int n;
    cin >> n;
    vector<pair<pair<int,int>,int>> vp;
    for(int i = 1; i <= n; i++){
        int x,y;
        cin >> x >> y;
        vp.pb({{x,y},i});
    }

    sort(all(vp),cmp);

    map<int,int> ind;
    ind[vp[0].ff.ss] = vp[0].ss;

    for(int i = 1; i < n; i++){
        auto it = ind.lower_bound(vp[i].ff.ss);
        if(it != ind.end()){
            cout << vp[i].ss << " " << ind[it->ff] << nl;
            return;
        }
        else ind[vp[i].ff.ss] = vp[i].ss;
    }

    cout << -1 << " " << -1 << nl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}