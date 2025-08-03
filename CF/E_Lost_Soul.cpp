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
#define lg(x)      (63 - __builtin_clzll(x)) //log base 2


#ifndef ONLINE_JUDGE
#include "debug.h" 
#else
  #define debug(x...)
#endif

void solve(){
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    inp(a)
    inp(b)


    if(a[n-1] == b[n-1]){
        cout << n << nl;
        return;
    }

    int ans = -1;
    vector<bool> seen(n+1);


    for(int i = n-2; i >= 0; i--){
        if(a[i] == b[i] || a[i] == a[i+1] || b[i] == b[i+1] || seen[a[i]] || seen[b[i]]){
            ans = i;
            break;
        }
        seen[a[i+1]] = seen[b[i+1]] = true;
    }

    ans++;
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