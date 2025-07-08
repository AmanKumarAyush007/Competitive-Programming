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
    vector<int> v(n);
    inp(v)

    vector<int> a = v;

    sort(all(a));

    int cnt = 0;
    vector<int> ans;

    for(int i = 0; i < n; i++){
        if(a[i] == v[i]){
            cnt++;
        }else {
            ans.pb(v[i]);
        }
    }

    if(cnt == n) cout << "NO\n";
    else{
        cout << "YES" << nl;
        cout << ans.size() << nl;
        for(auto &i : ans) cout << i << " ";
        cout << nl;
    }
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