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
    int a[n];
    inp(a);
    vector<int> p(n);
    int cnt = 0;
    set<int> st;
    for(int i = 0; i <= n; i++){
        st.insert(i);
    }
    for(int i = 0; i < n; i++){
        p[i] = *(st.begin());
        if(a[i] < 0){
            p[i] -= a[i];
        }
        st.erase(p[i]);
    }
    for(auto &i : p) cout << i << " ";
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