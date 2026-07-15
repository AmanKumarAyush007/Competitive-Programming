
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
#define inf              (int)1e18
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

    vector<int> pref1(n , 0), pref2(n , 0);

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        if(i == 0){
            pref1[i] = (x == 1 ? 1 : 0);
            pref2[i] = (x == 3 ? 1 : 0);
            continue;
        }

        pref1[i] = pref1[i - 1] + (x == 1 ? 1 : 0);
        pref2[i] = pref2[i - 1] + (x == 3 ? 1 : 0);
    }

    vector<int> suffmn(n, inf);

    for(int i = n-2; i >= 0; i--){
        suffmn[i] = min(suffmn[i+1], 2*pref2[i] - i);
    }

    for(int i = 0; i < n-1; i++){
        if(2*pref1[i] >= i+1 && 2*pref2[i] - i >= suffmn[i+1]){
            cout << "YES\n";
            return;
        }
    }

    cout << "NO\n";
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