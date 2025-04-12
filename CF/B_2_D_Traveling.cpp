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
    int n,k,a,b;
    cin >> n >> k >> a >> b;

    vector<pair<int,int>> vp;

    for(int i = 0; i < n; i++){
        int x,y;
        cin >> x >> y;
        vp.pb({x,y});
    }

    int x = vp[a-1].ff;
    int y = vp[a-1].ss;
    int p = vp[b-1].ff;
    int q = vp[b-1].ss;



    if(a <= k && b <= k) cout << 0;
    else{
        int ans = abs(x-p) + abs(y-q);

        vector<pair<int,int>> mid;
        for(int i = 0; i < k; i++){
            int c = vp[i].ff;
            int d = vp[i].ss;

            mid.pb({c,d});
        }


        if(mid.size() >= 2){
            int clo = LLONG_MAX;
            pair<int,int> seen;
            for(auto &[a,b] : mid){
                if(abs(a-x) + abs(b-y) < clo){
                    clo = abs(a-x) + abs(b-y);
                    seen = {a,b};
                }
            }
            int cl = LLONG_MAX;
            for(auto &[a,b] : mid){
                pair<int,int> temp = {a,b};
                
                if(temp!= seen) cl = min(cl,abs(a-p) + abs(b-q));
            }

            int tot = clo + cl;
            ans = min(ans,tot);
        }

        cout << ans;
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