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

using pi = pair<int,int>;

void solve(){
    int n,k,m;
    cin >> n >> k >> m;
    set<int> fri;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        fri.insert(x);
    }

    set<int> uni;

    vector<pi> con(k);
    for(int i = 0; i < k; i++){
        cin >> con[i].ff >> con[i].ss;
        if(!fri.count(con[i].ff)) uni.insert(con[i].ff);
        if(!fri.count(con[i].ss)) uni.insert(con[i].ss);
    }

    vector<int> v(all(uni));

    auto com = [&](int x, int y){
        fri.insert(x);
        fri.insert(y);

        int cnt = 0;
        for(auto &[a,b] : con) if(fri.count(a) && fri.count(b)) cnt++;

        fri.erase(x);
        if(x != y) fri.erase(y);

        return cnt;
    };

    int ans = 0;

    for(auto &[a,b] : con) if(fri.count(a) && fri.count(b)) ans++;

    for(int i = 0; i < uni.size(); i++){
        for(int j = i; j < uni.size(); j++){
            ans = max(com(v[i],v[j]), ans);
        }
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