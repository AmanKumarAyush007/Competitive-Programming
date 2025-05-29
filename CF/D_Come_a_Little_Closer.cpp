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
    int n;
    cin >> n;

    multiset<int> l,w;
    vector<pair<int,int>> vp;

    for(int i = 0; i < n; i++){
        int x,y;
        cin >> x >> y;
        vp.pb({x,y});
        l.insert(x);
        w.insert(y);
    }

    if(n == 1){
        cout << 1 << nl;
        return;
    }

    int ans = inf;

    for(int i = 0; i < n; i++){
        int x = vp[i].ff;
        int y = vp[i].ss;


        l.erase(l.find(x));
        w.erase(w.find(y));

        
        int diffL = (*prev(l.end())) - (*l.begin()) + 1;
        int diffW = (*prev(w.end())) - (*w.begin()) + 1;


        int temp = diffL * diffW;

        if(temp < n) temp = min(((diffL+1) * diffW) , ((diffW+1) * diffL));

        ans = min(temp,ans);
        
        l.insert(x);
        w.insert(y);

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