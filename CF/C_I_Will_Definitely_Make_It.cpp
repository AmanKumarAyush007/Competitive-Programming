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
    int k;
    cin >> k;
    vector<int> v(n);
    inp(v)

    int curr = v[k-1];

    set<int> s(all(v));

    vector<int> uni(all(s));

    auto it = lower_bound(all(uni),curr);
    int ind = it - uni.begin();

    for(int i = ind + 1; i < uni.size(); i++){
        if(uni[i] - uni[i-1] > curr){
            cout << "NO\n";
            return;
        }
    }

    debug(uni);
    cout << "YES" << nl;
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