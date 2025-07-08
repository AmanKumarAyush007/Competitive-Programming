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
#define rall(a)    (a).rbegin(),(a).rend()
#define sm(v)      accumulate(all(v),0LL)
#define inp(v)     for(auto& x : v) cin >> x;
#define setbit(x)  __builtin_popcountll(x)


void solve(){
    int n;
    cin >> n;
    int px,py,qx,qy;
    cin >> px >> py >> qx >> qy;
    vector<double> v(n);
    inp(v)

    
    double dis = sqrt(((px - qx) * (px - qx))+( (py - qy) * (py - qy)));


    if(n == 1){
        if(dis == v[0]) cout << "Yes\n";
        else cout << "No\n";
        return;
    }
    
    v.resize(n+1);
    v[n] = dis;
    sort(rall(v));

    
    double sum = 0;
    for(auto &i : v) sum += i;
    

    if(v[0] <= sum - v[0]) cout << "Yes";
    else cout << "No";

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