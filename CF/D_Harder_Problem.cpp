#include<bits/stdc++.h>
using namespace std;

#define int        int64_t
#define ff         first
#define ss         second
#define pb         push_back
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()
#define inp(v)     for(auto& x : v) cin >> x


void solve(){
    int n;
    cin >> n;
    int a[n];
    inp(a);
    set<int> s;
    for(auto &i : a) s.insert(i);
    set<int> t;
    for(int i = 1; i < n+1; i++){
        t.insert(i);
    }
    vector<int> ans;
    for(auto &i : a){
        if(s.find(i) != s.end()){
            ans.pb(i);
            s.erase(i);
            t.erase(i);
        }
    }
    for(auto &i : t) ans.pb(i);

    for(auto &i : ans) cout << i << " ";

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