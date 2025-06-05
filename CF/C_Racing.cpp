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
    vector<int> v(n);
    inp(v)

    vector<pair<int,int>> vp,valid;
    
    for(int i = 0; i < n; i++){
        int x,y;
        cin >> x >> y;
        vp.pb({x,y});
    }


    int l = 0, r = 0;
    for(int i = 0; i < n; i++){
        int x = vp[i].ff, y = vp[i].ss;

        if(v[i] == -1)r++;
        else if(v[i] == 1)l++,r++;

        l = max(x,l);
        r = min(y,r);

        if(r < l){
            cout << -1 << nl;
            return;
        }

        valid.pb({l,r});
    }

    int st = valid[n-1].ss;

    for(int i = n-1; i >= 0; i--){
        if(v[i] == 1) st--;
        else if(v[i] == -1){
            if(i == 0){
                if(st >= 0 && st <= 0) v[i] = 0;
                else {
                    st--;
                    v[i] = 1;
                }
                continue;
            }
            if(st >= valid[i-1].ff && st <= valid[i-1].ss) v[i] = 0;
            else {
                st--;
                v[i] = 1;
            }
        }
    }

    for(auto &i : v) cout << i << " ";

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