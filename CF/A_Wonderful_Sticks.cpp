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
    string s;
    cin >> s;
    set<int> st;
    int cnt = 0;
    for(auto &i : s) if(i == '<') cnt++;

    cnt++;
    cout << cnt << " ";
    st.insert(cnt);

    for(int i = 0; i < n-1; i++){
        if(s[i] == '<') {
            int ans = (*st.begin())-1;
            cout << ans << " ";
            st.insert(ans);
        }
        else {
            int ans = *st.rbegin();
            ans++;
            cout << ans << " ";
            st.insert(ans);
        }
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