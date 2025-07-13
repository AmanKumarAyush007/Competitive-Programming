#include<bits/stdc++.h>
using namespace std;

#define int        int64_t
#define ff         first
#define ss         second
#define pb         push_back
#define inf        LLONG_MAX
#define hell       LLONG_MIN
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()
#define sm(v)      accumulate(all(v),0LL)
#define inp(v)     for(auto& x : v) cin >> x;
#define setbit(x)  __builtin_popcountll(x)


void solve(){
    int n;
    cin >> n;
    vector<int> v(n), pre0(n), pre1(n);
    inp(v)
    string s;
    cin >> s;

    if(s[0] == '0'){
        pre0[0] = v[0];
    }
    else pre1[0] = v[0];


    for(int i = 1; i < n; i++){
        if(s[i] == '0'){
            pre0[i] = pre0[i-1]^v[i];
            pre1[i] = pre1[i-1];
        }
        else{
            pre1[i] = pre1[i-1]^v[i];
            pre0[i] = pre0[i-1];
        }
    }

    int x0 = pre0[n-1];
    int x1 = pre1[n-1];

    int q;
    cin >> q;

    while(q--){
        int k;
        cin >> k;
        if(k == 1){
            int l,r;
            cin >> l >> r;
            int range0 = pre0[r-1] ^ ((l == 1) ? 0 : pre0[l-2]);
            int range1 = pre1[r-1] ^ ((l == 1) ? 0 : pre1[l-2]);
            x0 = x0 ^ range0 ^ range1;
            x1 = x1 ^ range0 ^ range1;
        }
        else{
            int type;
            cin >> type;
            if(type == 1) cout << x1 << " ";
            else cout << x0 << " ";
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