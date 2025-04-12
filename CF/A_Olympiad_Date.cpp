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
    int a[n];
    inp(a);

    map<int,int> mp;

    for(int i = 0; i < n; i++){
        mp[a[i]]++;
        if(mp[0] >= 3 && mp[1] >= 1 && mp[3] >= 1 && mp[2] >=2 && mp[5] >= 1){
            cout << i+1 << nl;
            return;
        }
    }

    cout << 0;

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