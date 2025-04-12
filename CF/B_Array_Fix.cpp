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

bool sorted(int k){
    vector<int> v;
    while(k > 0){
        int ele = k%10;
        k /= 10;
        v.pb(ele);
    }
    reverse(all(v));
    return is_sorted(all(v));
}

pair<int,int> fl(int n){
    int f = -1,l = -1;

    while(n > 0){
        f = n%10;
        if(l == -1) l = f;
        n /= 10;
    }
    return {f,l};
}

void solve(){
    int n;
    cin >> n;
    vector<int> v(n);
    inp(v);
    if(is_sorted(all(v))) {
        cout << "YES\n";
        return;
    }
    vector<pair<int,int>> vp;
    for(int i = 0; i < n-1; i++){
        if(sorted(v[i])) vp.pb(fl(v[i]));
        else vp.pb({v[i],v[i]});
    }
    vp.pb({v[n-1],v[n-1]});
    vector<int> sol;

    for(int i = 0; i < n; i++){
        sol.pb(vp[i].ff);
        sol.pb(vp[i].ss);
    }

    cout << ((is_sorted(all(sol))) ? "YES" : "NO");


    // for(auto &[a,b] : vp) cout << a << " " << b << nl;



    cout << nl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    

    int t = 1;
    cin >> t;
    // cout << fl(t).ff << " " << fl(t).ss;
    while(t--){
        solve();
    }
    return 0;
}