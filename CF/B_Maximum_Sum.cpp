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
    
    int sm = accumulate(a,a+n,0LL);

    int pre[n];
    pre[0] = a[0];
    for(int i = 1; i < n; i++){
        pre[i] = pre[i-1] + a[i];
    }

    int suff[n];
    suff[n-1] = a[n-1];
    for(int i = n-2; i >= 0; i--){
        suff[i] = suff[i+1] + a[i];
    }

    int mn = INT_MAX;
    mn = min(suff[n-k],pre[2*k-1]);

    for(int i = 1; i < k; i++){
        int y = k - i;
        int x = 2*i;
        int te = suff[n-y] + pre[x - 1];
        mn = min(mn,suff[n-y] + pre[x - 1]);
    }

    cout << sm - mn;
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