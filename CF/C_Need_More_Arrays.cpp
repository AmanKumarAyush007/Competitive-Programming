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
    int n;
    cin >> n;
    int a[n];
    inp(a)

    int ans = 1;

    multiset<int> ms;
    for(auto &i : a) ms.insert(i);

    

    for(auto it = ms.begin(); it != ms.end(); it++){
        int x = *it;
        auto lbnd = next(it);
        while((lbnd != ms.end()) && (*lbnd - x < 2)) {
            ms.erase(lbnd);
            lbnd = next(it);
        }
    }

    cout << ms.size();

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