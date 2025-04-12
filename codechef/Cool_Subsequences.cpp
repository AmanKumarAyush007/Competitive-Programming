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
    int n;
    cin >> n;
    int ar[n];
    inp(ar);
    if(n == 1) {
        cout << -1 << nl;
        return;
    }
    map<int,int> mp;
    for(auto &i : ar) mp[i]++;
    for(auto &[a,b] : mp){
        if(b >= 2) {
            cout << 2 << nl;
            cout << a << " " << a << nl;
            return;
        }
    }

    cout << -1 << nl;
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