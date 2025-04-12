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
    int cnt0 = 0, cnt1 = 0;
    
    int ind = -1;

    for(auto &i : s){
        if(i == '0') cnt0++;
        else cnt1++;
    }

    for(int i = 0; i < n; i++){
        if(s[i] == '1') ind = i;
    }
    
    

    if(cnt1 == 0 ) cout << 0;
    else {
        cnt0 = 0;
        for(int i = 0; i < ind; i++){
            if(s[i] == '0') cnt0++;
        }
        cout << cnt1 + min(k,cnt0);
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