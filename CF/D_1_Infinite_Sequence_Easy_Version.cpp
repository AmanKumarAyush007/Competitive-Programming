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

// int ans(vector<int> &pre, int i){
//     if(i <= (pre.size() - 1)) return pre[i];
//     else ans(pre,i/2);
// }


void solve(){
    int n,l,r;
    cin >> n >> l >> r;
    int a[n+1];
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    vector<int> pre(n+1);
    pre[0] = 0;
    for(int i = 1; i <= n; i++){
        pre[i] = (pre[i-1]^a[i]);
    }
    // l == r
    // if(l <= n) cout << pre[l-1];
    // else{
    //     cout << ans(pre,l);
    // }

    for(auto &i : a) cout << i << " ";
    cout << nl;
    for(auto &i : pre) cout << i << " ";

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