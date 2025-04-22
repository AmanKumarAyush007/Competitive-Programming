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
    string s;
    cin >> s;

    int val = ((s[0] == '0') ? 1 : 2);

    for(int i = 1; i < n; i++){
        if(s[i] == s[i-1]) val++;
        else val += 2;
    }

    int x = 0, y = 0, z = 0;

    while(x < n && s[x] != '1') x++;
    y = x;
    while(y < n && s[y] != '0') y++;
    z = y;
    while(z < n && s[z] != '1') z++;

    if(x < n){
        if(y < n){
            if(z < n) val -= 2;
            else val--;
        }        
    }
    
    cout << val;
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