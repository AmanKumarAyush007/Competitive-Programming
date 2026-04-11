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

struct node{
    int open, close, pair;

    node (int a = 0, int b = 0, int c = 0){
        open = a;
        close = b;
        pair = c;
    }
};

const int N = 4e6 + 5;
node segTree[N];
string s;

node merge(node left, node right){
    node parent;

    int t = min(left.open, right.close);
    parent.pair = left.pair + right.pair + t;
    parent.close = left.close + right.close - t;
    parent.open = left.open + right.open - t;

    return parent;
}

void build(int ind, int l, int r){
    if(l == r) {
        if(s[l] == '(') segTree[ind] = node(1,0,0);
        else segTree[ind] = node(0,1,0);
        return;
    }

    int mid = (l+r)/2;

    build(2*ind, l, mid);
    build(2*ind + 1, mid + 1, r);

    segTree[ind] = merge(segTree[2*ind], segTree[2*ind + 1]);
}


node query(int ind, int l, int r, int ql, int qr){
    if(ql > r || qr < l) return node();

    if(ql <= l && qr >= r) return segTree[ind];

    int mid = (l+r)/2;

    node left = query(2*ind, l, mid, ql, qr);
    node right = query(2*ind + 1, mid + 1, r, ql, qr);

    return merge(left, right);
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> s;

    int n = s.size();

    build(1, 0, n-1);

    int q;
    cin >> q;

    while(q--){
        int l, r;
        cin >> l >> r;
        l-- , r--;

        cout << 2*query(1, 0, n-1, l, r).pair << nl;
    }
    return 0;
}