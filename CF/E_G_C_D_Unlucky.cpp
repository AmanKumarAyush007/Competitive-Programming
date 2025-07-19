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

#ifndef ONLINE_JUDGE
#include "debug.h" 
#else
  #define debug(x...)
#endif

void solve(){
    int n;
    cin >> n;
    vector<int> a(n),b(n);
    inp(a)
    inp(b)

    vector<int> ans(n,-1);
    ans[0] = a[0];
    ans[n-1] = b[n-1];

    for(int i = 1; i < n/2; i++){
        if(ans[i-1]%a[i] == 0) ans[i] = a[i];
        else{
            cout << "NO\n";
            return;
        }
        if(ans[n-1-i+1]%b[n-1-i] == 0) ans[n-1-i] = b[n-1-i];
        else{
            cout << "NO\n";
            return;
        }
    }

    debug(ans);

    if (n % 2 == 1) {
        int mid = n / 2;
        int g_val = gcd(a[mid], b[mid]);
        int L = (a[mid] / g_val) * b[mid];
        if (gcd(L, ans[mid-1]) != a[mid] || gcd(L, ans[mid+1]) != b[mid]) {
            cout << "NO\n";
            return;
        }
    } else {
        int mid = n / 2;
        int g_val = gcd(ans[mid-1], ans[mid]);
        if (g_val != a[mid] || g_val != b[mid-1]) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";

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