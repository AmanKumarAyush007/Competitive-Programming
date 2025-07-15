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
    vector<int> v(n);
    inp(v)

    
    map<int,int> mp;
    int g = 0;
    for(auto &i : v) {
        mp[i]++;
        g = gcd(g,i);
    }

    int reg = 3000;

    for(int i = 0; i < n-1; i++){
        int curr = 0;
        for(int j = i; j < n; j++){
            curr = gcd(v[j],curr);
            if(curr == 1) {
                reg = min(reg,j - i);
                break;
            }
        }
    }

    if(g != 1) cout << -1;
    else if(mp[1]) cout << n - mp[1];
    else cout << n-1 + reg;
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