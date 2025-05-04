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
    int n,m;
    cin >> n >> m;
    vector<int> a;
    multiset<int> b;
    for(int i = 0; i < n-1; i++){
        int x;
        cin >> x;
        a.pb(x);
    }

    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        b.insert(x);
    }

    a.pb(1);

    sort(all(a));

    for(int i = 0; i < n; i++){
        auto it = b.upper_bound(a[i]);
        if(it == b.end()) break;
        else{
            b.erase(it);
        }
    }

    cout << b.size();

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