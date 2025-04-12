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
    int a[n], b[n];
    inp(a)
    inp(b)

    int req = 0;
    int diff = inf;

    for(int i = 0; i < n; i++){
        req += min(abs(b[i] - a[i]), ((9+min(b[i],a[i]))-max(b[i],a[i])));
        int temp = max(abs(b[i] - a[i]), ((9+min(b[i],a[i]))-max(b[i],a[i]))) - min(abs(b[i] - a[i]), ((9+min(b[i],a[i]))-max(b[i],a[i])));
        if(temp%2 != 0) diff = min(diff,temp);
    }

    // cout << req;
    k -= req;
    
    if(k < 0) cout << "No";
    else{
        if(k%2 == 0 || k%9 == 0) cout << "Yes";
        else if(diff != inf && k-diff >= 0) cout << "Yes";
        else cout << "No";
    }
    
    // cout << ((req <= k) ? "Yes" : "No");
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