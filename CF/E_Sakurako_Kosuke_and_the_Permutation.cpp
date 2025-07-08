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
    vector<int> v(n+1);
    for(int i = 1; i <= n; i++){
        cin >> v[i];
    }

    set<int> st;
    for(auto &i : v) st.insert(i);

    int ans = 0;

    for(int i = 1; i <= n; i++){
        if(st.find(i) != st.end()){
            int j = i;
            int cnt = 1;
            while(v[j] != i){
                cnt++;
                j = v[j];
                st.erase(j);
            }
            if(cnt > 2) ans += ceil(1.0*cnt/2) - 1;
        }
    }
    cout << ans << nl;
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