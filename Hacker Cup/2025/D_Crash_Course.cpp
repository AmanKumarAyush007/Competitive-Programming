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
    string s;
    cin >> n >> s;

    int a[n], b[n];
    int na = 0, nb = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'A') a[na++] = i;
        else if (s[i] == 'B') b[nb++] = i;
    }

    int mn = min(na, nb);
    bool ok = false;

    for (int i = 0; i < mn; i++) {
        int x = a[i];
        int y = b[nb - 1 - i]; 
        if (x >= y) {
            ok = true;
            break;
        }
    }
    if (!ok) {
        if (na > nb) ok = true;
        else ok = false; 
    }

    if (ok) cout << "Alice" << nl;
    else cout << "Bob" << nl;
}

signed main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("crash_course_input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}
