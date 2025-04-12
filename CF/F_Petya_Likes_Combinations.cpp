#include<bits/stdc++.h>
using namespace std;

#define int        long long
#define ff         first
#define ss         second
#define pb         push_back
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()

void solve(){
    int n,k;
    cin >> n >> k;
    int a[n];
    for(auto &i : a) cin >> i;

    int j = 0;
    int ans = 0;

    for(int i = 0; i < n; i++){
        while(j<n && a[j]-a[i] <= k) j++;

        int diff = (j-1)-i;

        if(diff >= 2) ans += (diff*(diff - 1)) / 2;
    }    

    cout << ans;
    cout << nl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}