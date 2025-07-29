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
    int c;
    cin >> c;
    vector<int> v(n);
    inp(v)

    multiset<int> ms(all(v));
    debug(ms);

    for(int i = 0; i < 30; i++){
        // if(i > 5) break;
        if(c >= (1LL << i)){
            debug(c/(1LL << i));
            auto it = lower_bound(all(ms),(c/(1LL << i)) + 1);

            if(it != ms.begin()){

                it = prev(it);
                // debug(*it);
                if(it != ms.end() && (*it <= c/(1LL << i))) ms.erase(it);
            }
           

        }
    }

    cout << ms.size() << nl;
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