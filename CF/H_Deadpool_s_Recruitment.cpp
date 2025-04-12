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
    int n, t1, t2, k;
    cin >> n >> t1 >> t2 >> k;
    vector<pair<int,int>> vp;
    while(n--){
        int a, b;
        cin >> a >> b;
        if(a > b) swap(a,b);
        vp.pb({a,b});
    }
    vector<pair<double,int>> sol;

    for(int i = 0; i < n; i++){
        int a = vp[i].ff;
        int b = vp[i];
        double val = a*t1 - (a*t1*k*1.0)/100 + b*t2;
        sol.pb({val,i+1});
    }
    sort(all(sol));
    for(int i = 0; i < n; i++){
        cout << sol[i].ss << " " << sol[i].ff << nl;
    }


    // cout << nl;
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