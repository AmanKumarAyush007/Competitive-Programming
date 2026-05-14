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

const int N = 1e5 + 5;
vector<int> segTree(4*N);
vector<int> diff;
int n, q;

void build(int ind = 0, int lo = 0, int hi = n-2){
    if(lo == hi) {
        segTree[ind] = diff[lo];
        return;
    }

    int mid = (lo+hi)/2;
    build(2*ind+1, lo, mid);
    build(2*ind+2, mid+1, hi);

    segTree[ind] = gcd(segTree[2*ind+1], segTree[2*ind+2]);
}

int query(int l, int r, int ind = 0, int st = 0, int en = n-2){
    if(r < st || en < l) return 0;
    if(l <= st && en <= r) return segTree[ind];

    int mid = (st+en)/2;

    return gcd(query(l, r, 2*ind + 1, st, mid), query(l, r, 2*ind + 2, mid + 1, en));
}

void solve(){
    cin >> n >> q;

    vector<int> v(n);
    inp(v);

    diff.clear();
    for(int i = 0; i < n-1; i++){
        diff.pb(abs(v[i+1] - v[i]));
    }
    
    segTree.assign(4*n + 5, 0);

    if(n > 1) build();

    while(q--){
        int l, r;
        cin >> l >> r;
        l--, r--;
        if(l == r) cout << 0 << " ";
        else cout << query(l, r-1) << " ";
    }
    
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