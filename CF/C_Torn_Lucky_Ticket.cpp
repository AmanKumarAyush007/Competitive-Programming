#include<bits/stdc++.h>
using namespace std;

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


#ifndef ONLINE_JUDGE
#include "debug.h" 
#else
  #define debug(x...)
#endif

void solve(){
    int n;
    cin >> n;

    vector<string> v(n);
    inp(v)

    int ans = 0;


    auto dig = [&](string s){
        int res = 0;
        for(int i = 0; i < s.size(); i++){
            res += s[i] - '0';
        }
        return res;
    };

    map<pair<int,int>,int> mp;

    for(auto &i : v) mp[{i.size(),dig(i)}]++;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < 2; j++){
            for(int k = 0; k < v[i].size() - j; k++){
                int half = k + 1;
                int halfsum = dig(string(v[i].begin(),v[i].begin() + half));

                int rest = v[i].size() - half;
                int restsum = dig(string(v[i].begin() + half, v[i].end()));

                int need = half - rest;
                int needsum = halfsum - restsum;

                ans += mp[{need,needsum}];
            }
            reverse(all(v[i]));
        }
    }


    cout << ans << nl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}