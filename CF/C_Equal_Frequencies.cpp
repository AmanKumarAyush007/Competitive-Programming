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

    map<char,int> mp;
    for(int i = 0; i < 26; i++){
        mp['a' + i] = 0;
    }

    for(auto &i : s) mp[i]++;

    vector<pair<int,char>> cnt;

    for(auto &[x,y] : mp) cnt.pb({y,x});
    sort(all(cnt), greater<>());


    int uni = 0;
    int mn = inf;

    for(int i = 1; i <= cnt.size(); i++){
        if(n%i) continue;

        int unchanged = 0;
        for(int j = 0; j < i; j++){
            auto [fre, ch] = cnt[j];
            unchanged += min(fre, n/i);
        }
        int changed = n - unchanged;

        if(mn > changed) {
            mn = changed;
            uni = i;
        }
    }


    int req = n / uni;

    map<char,int> used;

    for(int i = 0; i < uni; i++){
        used[cnt[i].ss] = req;
    }


    string ans(n,' ');

    for(int i = 0; i < n; i++){
        if(used[s[i]]){
            ans[i] = s[i];
            used[s[i]]--;
        }
    }


    for(int i = 0; i < n; i++){
        if(ans[i] == ' '){
            while(!used.empty() && ((used.begin() -> ss) == 0)) used.erase(used.begin());

            auto ch = used.begin() -> ff;

            ans[i] = ch;

            used[ch]--;
        }
    }

    cout << mn << nl << ans;
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