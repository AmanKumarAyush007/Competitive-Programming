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
    vector<int> v(n);
    inp(v)
    set<int> st;
    for(auto &i : v) st.insert(i);
    if(st.size() == 1) {
        cout << "YES\n";
        return;
    }
    int x = 0;
    for(auto &i : v) x ^= i;

    if(x == 0) cout << "YES";
    else{
        int k = 0;
        int cnt = 0;
        for(int i = 0; i < n; i++){
            k ^= v[i];
            if(k == x){
                cnt++;
                k = 0;
            }
            if(cnt > 2) {
                cout << "YES\n";
                return;
            }
        }
        cout << "NO";
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