#include<bits/stdc++.h>
using namespace std;

#define int        int64_t
#define ff         first
#define ss         second
#define pb         push_back
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()
#define inp(v)     for(auto& x : v) cin >> x


void solve(){
    int n,k;
    cin >> n >> k;
    int a[n];
    inp(a);

    vector<int> bit(31,0);

    for(int i = 0; i < n; i++){
        for(int j = 30; j >= 0; j--){
            if((a[i] & (1LL << j))) bit[30-j]++;
        }
    }

    for(int i = 0; i <= 30; i++){
        if(k == 0) break;
        if(bit[i] != n && (n - bit[i] <= k)){
            int rest = n - bit[i];
            k -= rest;
            bit[i] = n;
        }
    }

    int ans = 0;

    for(int i = 0; i <= 30; i++){
        if(bit[i] == n) ans |= (1LL << (30-i));
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