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

int f(int n, int m){
    string s = to_string(n);
    string t = to_string(m);
    int ans = 0;
    int i = s.size()-1;

    while(i >= 0 ){
        if(s[i] == t[i]){
            ans++;
            // cout << i << s[i] << t[i] << nl;
        }
        i--;
    }
    return ans;
}

void solve(){
    int l,r;
    cin >> l >> r;

    for(int i = l; i <= r; i++){
        cout << i << " " << f(l,i) + f(i,r) << nl;
    }

    cout << nl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // cout << f(101,1000);

    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}