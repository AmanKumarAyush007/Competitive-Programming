#include<bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h" 
#else
#define debug(x...)
#endif
#define int              int64_t
#define ff               first
#define ss               second
#define pb               push_back
#define inf              LLONG_MAX
#define hell             LLONG_MIN
#define nl               '\n'
#define all(a)           (a).begin(),(a).end()
#define rall(a)          (a).rbegin(),(a).rend()
#define sm(v)            accumulate(all(v),0LL)
#define inp(v)           for(auto& x : v) cin >> x;
#define setbit(x)        __builtin_popcountll(x)
#define lg(x)            (63 - __builtin_clzll(x)) //log base 2
#define prefixsum(a)     partial_sum(all(a), (a).begin());
#define suffixsum(a)     partial_sum(rall(a), (a).rbegin());



void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;

    set<char> st;
    for(auto &i : s) st.insert(i);

    if(st.size() == 1){
        if(*st.begin() == '0') cout << 0 << " " << 0 << nl;
        else cout << n << " " << 0 << nl;
    }
    else{
        vector<int> one;
        for(int i = 0; i < n; i++){
            if(s[i] == '1') one.pb(i);
        }

        int cnt0 = 0, cnt1 = 0;
        int ans = 0, req = 0;

        int curr = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == '0') cnt0++;
            else cnt1++;

            if(cnt1 < cnt0){
                while(curr < one.size() && one[curr] < i) curr++;
                if(curr >= one.size()) continue;
                int ind = one[curr];
                req += ind - i;
                swap(s[i],s[ind]);
                ans++;
                curr++;
                cnt0--;
                cnt1++;
            }
            else ans++;
        }

        cout << ans << " " << req << nl;
    }
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