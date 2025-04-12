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
    int n,k;
    cin >> n >> k;
    int a[n];
    inp(a);
    sort(a,a+n);
    if(n == 1) cout << 0;
    else{
        int diff[n-1];
        for(int i = 0; i < n-1; i++){
            diff[i] = a[i+1] - a[i];
        }
        int mx = -1;
        int curr = 0;
        for(int i = 0; i < n-1; i++){
            if(diff[i] <= k) curr++;
            else curr = 0;
            // cout << curr << " ";
            mx = max(curr,mx);
        }
        mx++;
        cout << n-mx;
    }

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