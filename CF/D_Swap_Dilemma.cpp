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

int fn(vector<int>& A, vector<int>& B) {
    int n = A.size();
    unordered_map<int,int> pos;

    for(int i = 0; i < n; i++)
        pos[A[i]] = i;

    int swaps = 0;

    for(int i = 0; i < n; i++) {
        if (A[i] == B[i]) continue;

        int correctIdx = pos[B[i]];

        swap(A[i], A[correctIdx]);

        pos[A[correctIdx]] = correctIdx;
        pos[A[i]] = i;

        swaps++;
    }
    return swaps;
}


void solve(){
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    inp(a);
    inp(b);

    vector<int> c = a, d = b;

    sort(all(c));
    sort(all(d));

    if(c != d) cout << "NO";
    else{
        int req = fn(a,b);
        debug(req);
        cout << (req%2 ? "NO" : "YES");
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