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

    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];

    int mx = *max_element(a.begin(), a.end());

    vector<vector<int>> lists(n);

    for(int i = 0; i < n; i++){
        int x = a[i];
        while(x <= 2 * mx){
            lists[i].push_back(x);
            x *= 2;
        }
    }

    priority_queue<
        tuple<int,int,int>,
        vector<tuple<int,int,int>>,
        greater<>
    > pq;

    int currmx = LLONG_MIN;

    for(int i = 0; i < n; i++){
        pq.push({lists[i][0], i, 0});
        currmx = max(currmx, lists[i][0]);
    }

    int ans = LLONG_MAX;

    while(true){
        auto [val, i, j] = pq.top();
        pq.pop();

        ans = min(ans, currmx - val);

        if(j + 1 == lists[i].size())
            break;

        int next_val = lists[i][j+1];
        pq.push({next_val, i, j+1});
        currmx = max(currmx, next_val);
    }

    cout << ans << "\n";
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