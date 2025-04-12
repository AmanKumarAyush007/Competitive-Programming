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
    if(n < 3){
        cout << 0;
    }
    else{
        int x = 0,y = 0;
        for(auto &i : s){
            if(i == '_') x++;
            else y++;
        }
        // cout << x << " " << y;
        if(x < 1 || y < 2) cout << 0;
        else{
            int l = y/2;
            int r = y - l;
            // cout << l << " " << r;
            cout << l*r*x;
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