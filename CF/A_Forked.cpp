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
    int a,b;
    cin >> a >> b;
    int kx,ky,qx,qy;
    cin >> kx >> ky >> qx >> qy;
    map<pair<int,int>,int> mpk;
    map<pair<int,int>,int> mpq;

    mpk[{kx+a,ky-b}]++;
    mpk[{kx+a,ky+b}]++;
    mpk[{kx-a,ky-b}]++;
    mpk[{kx-a,ky+b}]++;

    mpq[{qx+a,qy-b}]++;
    mpq[{qx+a,qy+b}]++;
    mpq[{qx-a,qy-b}]++;
    mpq[{qx-a,qy+b}]++;

    mpk[{kx+b,ky-a}]++;
    mpk[{kx+b,ky+a}]++;
    mpk[{kx-b,ky-a}]++;
    mpk[{kx-b,ky+a}]++;

    mpq[{qx+b,qy-a}]++;
    mpq[{qx+b,qy+a}]++;
    mpq[{qx-b,qy-a}]++;
    mpq[{qx-b,qy+a}]++;

    int ans = 0;

    for(auto &[a,b] : mpk){
        if(mpq[a]) ans++;
    }

    cout << ans;
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