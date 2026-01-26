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
    int n,q;
    cin >> n >> q;

    vector<int> v(n);
    inp(v);

    vector<int> pre = v;

    prefixsum(pre);

    auto calc = [&](int st, int en){
        int res = 0;
        
        if(en < st) res = pre[n-1] - (pre[st-1] - pre[en]);
        else res = pre[en] - (st > 0 ? pre[st-1] : 0);

        return res;
    };

    auto turn = [&](int x){
        return (x/n)%n;
    };

    auto net = [&](int l, int r, int lo, int hi){

        debug(l,r,lo,hi);

        int res = 0;

        if(lo - 1 >= 0 && lo-1 >= l){
            int prev = max(0LL,lo - n);
            int g1 = l - prev;
            int g2 = lo-1 - prev;

            int st = ((prev/n) + g1) % n;
            int en = ((prev/n) + g2) % n;

            debug(st,en);

            res += calc(st,en);
        }

        if(hi + 1 < n*n && hi + 1 <= r){
            int diff = r - (hi + 1);

            int st = (hi+1)/n;
            int en = (st + diff) % n;

            debug(st,en);
            res += calc(st,en);
        }
        
        return res;
    };
    
    while(q--){
        int l, r;
        cin >> l >> r;
        l--, r--;
        int diff = r - l;
        int len = diff+1;
        int ans = 0;


        if(turn(l) == turn(r)){
            int gap = l - (turn(l)*n);
            int st = (turn(l) + gap) % n;
            int en = (st + diff)%n;
            ans = calc(st,en);
        }
        else{
            int lo = ((l/n + (l%n != 0))) * n;
            int x = turn(r) - 1;
            int hi = n*(x)  + (n-1);
            if((hi + n) == r) hi += n;
            
            debug(lo, hi);

            if(hi > r) hi -= n;

            if(lo <= hi && ((hi - lo + 1)%n == 0)){
                ans += pre[n-1] * ((hi - lo + 1)/n);
                ans += net(l,r,lo,hi);
            }
            else{
                ans += net(l,r,lo,lo-1);
            }
            // debug(lo,hi);
        }
        
        cout << ans << nl;
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