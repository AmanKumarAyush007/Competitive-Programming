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
#define lg(x)            (63 - __builtin_clzll(x))
#define prefixsum(a)     partial_sum(all(a), (a).begin());
#define suffixsum(a)     partial_sum(rall(a), (a).rbegin());



void solve(){
    int n,m,k;
    cin >> n >> m >> k;

    vector<int> loc(n), spi(m);
    inp(loc);
    inp(spi);

    string s;
    cin >> s;

    sort(all(spi));

    vector<int> p(k+1, -1), neg(k+1, -1);

    int cur = 0;
    for(int i=0;i<k;i++){
        if(s[i]=='L') cur--;
        else cur++;

        if(cur > 0 && cur <= k && p[cur] == -1)
            p[cur] = i + 1;
        if(cur < 0 && -cur <= k && neg[-cur] == -1)
            neg[-cur] = i + 1;
    }

    vector<int> death(n, k+1);

    for(int i=0;i<n;i++){
        int x = loc[i];
        auto it = lower_bound(all(spi), x);

        if(it != spi.end()){
            int d = *it - x;
            if(d <= k && p[d] != -1)
                death[i] = min(death[i], p[d]);
        }

        if(it != spi.begin()){
            it--;
            int d = x - *it;
            if(d <= k && neg[d] != -1)
                death[i] = min(death[i], neg[d]);
        }
    }

    sort(all(death));

    int ptr = 0;
    for(int i=1;i<=k;i++){
        while(ptr < n && death[ptr] <= i) ptr++;
        cout << n - ptr << " ";
    }
    cout << nl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
