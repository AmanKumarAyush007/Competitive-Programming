#include<bits/stdc++.h>
using namespace std;

#define int        int64_t
#define ff         first
#define ss         second
#define pb         push_back
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()

void solve(){
    int n,k;
    cin >> n >> k;
    int a[n],b[n];
    for(auto &i : a) cin >> i;
    for(auto &i : b) cin >> i;

    int mul[n];

    for(int i = 0; i < n; i++){
        mul[i] = a[i] * b[i];
    }
    sort(mul,mul+n,greater<int>());
    int l = 0,ans = 0;
    for(int i = 0; i < n; i++){
        l += mul[i];
        ans++;
        if(l >= k) break;
    }
    // int i = n-1
    if(l < k) ans = -1;
    cout << ans << nl;
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