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

    vector<int> k(n),c(m);
    inp(k)
    inp(c)

    multiset<int> st;

    for(auto &i : c) st.insert(i);

    sort(all(k),greater<int>());

    int ans = 0;

    for(int i = 0; i < n; i++){
        auto it = st.begin();
        if(it == st.end()) ans += c[k[i] - 1];
        else if(c[k[i] - 1] > *it){
            ans += *it;
            st.erase(it);
        }
        else ans += c[k[i] - 1];
    }

    cout << ans;
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