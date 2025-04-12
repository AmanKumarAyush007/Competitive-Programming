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
    int n,x,k;
    cin >> n >> x >> k;
    string s;
    cin >> s;
    int curr = x;
    int i = 0;
    while(i < n && k && curr != 0){
        // cout << i << " " << k << " " << curr;
        if(s[i] == 'L') curr--;
        else curr++;
        i++;
        k--;
    }
    if(curr != 0) cout << 0;
    else{
        i = 0;
        if(k){
            if(s[i] == 'L') curr--;
            else curr++;
            i++;
        }
        else{
            cout << 1 << nl;
            return;
        }
        while(i < n && curr){
            if(s[i] == 'L') curr--;
            else curr++;
            i++;
        }
        if(curr) cout << 1;
        else cout << k/i+1;
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