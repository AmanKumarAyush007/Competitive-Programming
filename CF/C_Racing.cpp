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



bool check (vector<bool> &dp,<pair<int,int>> &vp, vector<int> &v, int i){
    int l = vp[i].ff;
    int r = vp[i].ss;

    if(i == 0){
        if(v[i] == -1) dp[i] = ((l <= 0 && 0 <= r) || (l <= 1 && 1 <= r));
        else dp[i] = ((l <= v[i] && v[i] <= r) || (l <= v[i] && v[i] <= r));

        return dp[i];
    }

    

}


void solve(){
    int n;
    cin >> n;
    vector<int> v(n);
    inp(v)

    vector<pair<int,int>> vp;

    for(int i = 0; i < n; i++){
        int x,y;
        cin >> x >> y;
        vp.push_back({x,y});
    }


    
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