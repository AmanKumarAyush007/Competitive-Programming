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



map<pair<int,int>, vector<int>> mp;

void gen(int d1, int d2, vector<int>& nums) {

    queue<int> q;

    nums.push_back(0);

    if(d1 != 0) {
        q.push(d1);
        nums.push_back(d1);
    }

    if(d2 != 0) {
        q.push(d2);
        nums.push_back(d2);
    }

    while(!q.empty()) {

        int cur = q.front();
        q.pop();

        if(cur > (int)1e16) continue;

        int x = cur * 10 + d1;
        int y = cur * 10 + d2;

        if(x <= (int)1e17) {
            nums.push_back(x);
            q.push(x);
        }

        if(d1 != d2 && y <= (int)1e17) {
            nums.push_back(y);
            q.push(y);
        }
    }
}

void build() {

    for(int d1 = 0; d1 <= 9; d1++) {

        for(int d2 = d1 + 1; d2 <= 9; d2++) {

            vector<int>& nums = mp[{d1, d2}];

            gen(d1, d2, nums);

            sort(all(nums));

            nums.erase(unique(all(nums)), nums.end());
        }
    }
}

void solve() {

    int a, n;
    cin >> a >> n;

    int d1, d2;
    cin >> d1 >> d2;

    auto &nums = mp[{d1, d2}];

    int ans = inf;

    auto it = lower_bound(all(nums), a);

    if(it != nums.end())
        ans = min(ans, abs(*it - a));

    if(it != nums.begin()) {
        it--;
        ans = min(ans, abs(*it - a));
    }

    cout << ans << nl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    build();

    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}