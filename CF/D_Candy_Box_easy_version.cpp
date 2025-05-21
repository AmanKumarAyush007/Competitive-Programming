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
    inp(a);

    map<int,int> mp;

    for(auto &i : a) mp[i]++;

    int ans = 0;

    multiset<int> ms;

    for(auto &[a,b] : mp){
        ms.insert(b);
    }

    int mx = *ms.rbegin();

    for(int i = mx; i >= 1; i--){
        auto it = ms.lower_bound(i);
        if(it != ms.end()){
            ans += i;
            ms.erase(it);
        }
    }

    cout << ans ;
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