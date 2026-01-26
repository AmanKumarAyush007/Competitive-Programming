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

long long fn(vector<long long>& a) {
    int n = a.size();

    vector<long long> pref(n + 1, 0), suff(n + 1, 0);
    for (int i = 2; i <= n; i += 2) {
        pref[i] = pref[i - 2] + (a[i - 1] - a[i - 2]);
    }

    for (int i = n - 2; i >= 0; i -= 2) {
        suff[i] = suff[i + 2] + (a[i + 1] - a[i]);
    }

    long long ans = LLONG_MAX;

    for (int skip = 0; skip < n; skip += 2) {
        long long cost = pref[skip] + suff[skip + 1];
        ans = min(ans, cost);
    }

    return ans;
}

void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    inp(v);

    map<int,vector<int>> mp;

    for(auto &i : v) mp[i%k].pb(i);

    int cnt = 0;

    for(auto &[a,b] : mp){
        if(b.size() % 2 == 1) cnt++;
        if((cnt && n%2 == 0) || (cnt > 1)) {
            cout << -1 << nl;
            return;
        }
    }

    int val;

    int ans = 0;

    for(auto &[a,b] : mp){
        sort(all(b));
        if(b.size() % 2){
            val = a;
            continue;
        }
        int curr = 0;
        for(int j = 0; j < b.size()-1; j += 2){
            int temp = b[j+1] - b[j];
            curr += temp;
        }
        ans += curr/k;
    }


    if(n%2 && mp[val].size() > 1){
        ans += fn(mp[val])/k;
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