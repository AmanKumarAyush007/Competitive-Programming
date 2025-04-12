#include<bits/stdc++.h>
using namespace std;

#define int        int64_t
#define ff         first
#define ss         second
#define pb         push_back
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()
#define inp(v)     for(auto& x : v) cin >> x
#define sm(v)      accumulate(all(v),0LL)


void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> v(n);
    set<char> st;
    for(int i = 0; i < n; i++){
        st.insert(s[i]);
        v[i] = st.size();
    }
    // for(auto &i : v) cout << i << " ";
    int ans = 0;
    for(int i = 1; i < n; i++){
        ans += v[i-1];
    }

    cout << st.size() + ans << nl;
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