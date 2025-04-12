#include<bits/stdc++.h>
using namespace std;

#define int        int64_t
#define ff         first
#define ss         second
#define pb         push_back
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()

void solve(){
    int n;
    cin >> n;
    int a[n],b[n];
    for(auto &i : a) cin >> i;
    for(auto &i : b) cin >> i;

    vector<pair<int,int>> vp;
    
    for(int i = 0; i < n; i++){
        vp.pb({a[i],b[i]});
    }
    sort(all(vp));

    int t = 0;
    int i = n-1;

    while((t + vp[i].ss)<= vp[i].ff){
        t+= vp[i].ss;
        i--;
        if(i < 0) break;
    }

    cout << ((i < 0) ? t : max(t,vp[i].ff));
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