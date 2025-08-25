#include<bits/stdc++.h>
using namespace std;

#define int              int64_t
#define ff               first
#define ss               second
#define pb               push_back
#define inf              LLONG_MAX
#define hell             LLONG_MIN
#define nl               '\n'
#define all(a)           (a).begin(),(a).end()
#define rall(a)          (a).rbegin(),(a).rend()
#define sm(v)            accumulate(all(v),0LL)
#define inp(v)           for(auto& x : v) cin >> x;
#define setbit(x)        __builtin_popcountll(x)
#define lg(x)            (63 - __builtin_clzll(x)) //log base 2
#define prefixsum(a)     partial_sum(all(a), (a).begin());
#define suffixsum(a)     partial_sum(rall(a), (a).rbegin());


#ifndef ONLINE_JUDGE
#include "debug.h" 
#else
  #define debug(x...)
#endif

void solve(){
    int n,m,k;
    cin >> n >> m >> k;
    if(abs(n-m) > k) cout << -1;
    else if(max(n,m) < k) cout << -1;
    else{
        string ans;
        int till = k;
        while(till--){
            if(n > m) ans += '0';
            else ans += '1';
        }
        int tl = n+m;
        if(n > m) {
            n -= k;
            int i = 0;
            while(ans.size() != tl){
                if(i % 2 == 0 && m > 0) ans += '1', m--;
                else if(i % 2 == 1 && n > 0) ans += '0', n--;
                i++;
            }
        }
        else {
            m -= k;
            int i = 0;
            while(ans.size() != tl){
                if(i % 2 == 1 && m > 0) ans += '1', m--;
                else if(i % 2 == 0 && n > 0) ans += '0', n--;
                i++;
            }

        }
        cout << ans;
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





// 1111111111111111111110101010101010101010
// 1111111111111111111110101010101000000000 -> ans
// 1111111111111111111110101010101000000000
