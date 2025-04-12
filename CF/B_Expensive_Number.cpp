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

// string sum(string s){
//     int n = s.size();
//     int req = 0;
//     for(int i = 0; i < n; i++){
//         req += s[i] - '0';
//     }
//     return to_string(req);
// }


void solve(){
    string s;
    cin >> s;
    int ans = 0;
    
    while(s.back() == '0') {
        ans++;
        s.pop_back();
    }

    while(s.size() != 1){
        if(s[0] == '0') s.erase(0,1);
        else {
            s.erase(0,1);
            ans++;
        }
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