#include<bits/stdc++.h>
using namespace std;

#define int        int64_t
#define ff         first
#define ss         second
#define pb         push_back
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()
#define inp(v)     for(auto& x : v) cin >> x
#define sm(v)      accumulate(all(v),0LL)


void solve(){
    int n;
    cin >> n ;
    int a[2*n];
    inp(a);
    sort(a,a+2*n);
    vector<int> sl, bg;
    int x = a[n-1];
    int y = a[2 * n - 1];
    for (int i = 0; i < 2 * n; i++){
        if (i < n && a[i] != x)
            sl.pb(a[i]);
        else if (i >= n && a[i] != y)
            bg.pb(a[i]);
    }
    int to_sl = sm(sl);
    int to_bg = sm(bg);
    bg.pb(x);
    bg.pb(y);
    int nw = (to_bg - to_sl) + x + y;
    sl.pb(nw);
    int p = 0, q = 0;
    for (int i = 0; i < 2 * n + 1; i++){
        if (i % 2 == 1){
            cout << sl[p] << " ";
            p++;
        }
        else{
            cout << bg[q] << " ";
            q++;
        }
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