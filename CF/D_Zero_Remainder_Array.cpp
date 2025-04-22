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
    int a[n];
    inp(a)

    map<int,int> mp;

    set<int> st;

    for(auto &i : a){
        if(i % k == 0) continue;
        mp[i%k]++;
        st.insert((k*mp[i%k]) - (i%k));
    }

    if(st.empty()) cout << 0;
    else cout << *st.rbegin() + 1;   

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