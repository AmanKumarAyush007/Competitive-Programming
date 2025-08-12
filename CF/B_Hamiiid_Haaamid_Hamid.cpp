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
#define lg(x)      (63 - __builtin_clzll(x)) //log base 2


#ifndef ONLINE_JUDGE
#include "debug.h" 
#else
  #define debug(x...)
#endif

void solve(){
    int n,x;
    cin >> n >> x;
    string s;
    cin >> s;

    set<char> st;
    for(auto &i : s) st.insert(i);

    if(st.size() == 1 || x == 1 || x == n) cout << 1;
    else {
        int l = 0;
        int i = x - 2;
        while(i >= 0 && s[i] == '.'){
            l++;
            i--;
        }

        int r = 0;
        i = x;
        while(i < n && s[i] == '.'){
            r++;
            i++;
        }

        cout << max(min(x-l,n-x+1),min(x,n-x+1-r));
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