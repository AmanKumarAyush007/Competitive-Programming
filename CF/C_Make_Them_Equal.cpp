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
    char c;
    cin >> c;
    string s;
    cin >> s;
    vector<int> v;
    for(int i = 0; i < n; i++){
        if(s[i] != c) v.pb(i+1);
    }
    if(v.size() == 0) cout << 0;
    else{
        bool check = false;
        for(int i = 0; i < v.size(); i++){
            if(v[i] == n){
                check = true;
            }
        }
        sort(all(v));
        
        if(!check) cout << 1 << nl << n;
        else if(ans) cout << 1 << nl << ans;
        else {
            cout << 2 << nl << n << " " << n-1;
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