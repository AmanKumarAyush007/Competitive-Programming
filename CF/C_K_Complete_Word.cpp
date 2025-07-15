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
    int n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    map<char,int> mp;

    int ans = 0;
    for(int i = 0; i < k/2; i++){
        int j = i;
        while(j < n){
            mp[s[j]]++;
            j += k;
        }
        j = k - i - 1;
        while(j < n){
            mp[s[j]]++;
            j += k;
        }
        int mx = hell;
        for(auto &[a,b] : mp) mx = max(b,mx);
        ans += ((n/k)*2) - mx;
        mp.clear();
    }

    
    if(k%2 != 0){
        for(int i = k/2; i < n; i += k){
            mp[s[i]]++;
        }
        int mx = hell;
        for(auto &[a,b] : mp) mx = max(b,mx);
        ans += (n/k) - mx;
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