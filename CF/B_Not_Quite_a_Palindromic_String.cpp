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
    int n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    map<int,int> mp;

    for(auto &i : s) mp[i-'0']++;

    for(int i = 0; i <= k; i++){
        int x = i;
        int y = k-x;
        if(mp[0] >= 2*x && mp[1] >= 2*y){
            if((mp[0] - 2*x ) == (mp[1] - 2*y)) {
                cout << "YES\n";
                return;
            }
        }
    }
    cout << "NO" << nl;
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