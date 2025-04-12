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
    int ans = 1;
    int curr = 1;
    for(int i = 1; i < n; i++){
        if(s[i] == s[i-1]) curr++;
        else curr = 1;
        ans = max(ans,curr);
    }
    cout << ans + 1<< nl;
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