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
    string s;
    cin >> s;

    vector<int> v;

    for(int i = 0; i < n; i++){
        if(s[i] == '*') v.pb(i);
    }


    int m = v.size() / 2;
    int ans = 0;


    for(int i = 0; i < v.size(); i++){
        int st = v[i];
        ans += abs(st - (v[m]-(m - i)));
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