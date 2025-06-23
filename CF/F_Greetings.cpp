#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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


template<typename T>
using ordered_set = __gnu_pbds::tree<T, __gnu_pbds::null_type, std::less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;


void solve(){
    int n;
    cin >> n;
    vector<pair<int,int>> vp;
    while(n--){
        int x,y;
        cin >> x >> y;
        vp.pb({x,y});
    }
    sort(all(vp));

    ordered_set<int> st;

    st.insert(vp[0].ss);

    int ans = 0;

    for(int i = 1; i < vp.size(); i++){
        ans += st.size() - st.order_of_key(vp[i].ss);
        st.insert(vp[i].ss);
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