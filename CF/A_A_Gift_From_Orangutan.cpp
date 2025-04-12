#include<bits/stdc++.h>
using namespace std;

#define int        long long
#define ff         first
#define ss         second
#define pb         push_back
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()

void solve(){
    int n;
    cin >> n;
    int a[n];
    int mn = INT_MAX;
    int mx = INT_MIN;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        mn = min(mn,a[i]);
        mx = max(mx,a[i]);
    }

    cout<< (n-1) * (mx-mn) << nl;
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