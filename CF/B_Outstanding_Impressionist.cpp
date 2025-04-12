#include<bits/stdc++.h>
using namespace std;

#define int        int64_t
#define ff         first
#define ss         second
#define pb         push_back
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()
#define inp(v)     for(auto& x : v) cin >> x


void solve(){
    int n;
    cin >> n;
    int k = n;
    vector<pair<int,int>> vp;
    set<int> s;
    map<int,int> mp;
    while(k--){
        int a,b;
        cin >> a >> b;
        vp.pb({a,b});
        if(a == b) {
            s.insert(a);
            mp[a]++;
        }
    }
    vector<int> v(all(s));
    
    if(s.size() == 0) cout << string(n,'1');
    else{
        for(int i = 0; i < n; i++){
            int l = vp[i].ff;
            int r = vp[i].ss;
            if(l == r) {
                if(mp[l] == 1) cout << 1;
                else cout << 0;
                continue;
            }
            
            auto lbl =lower_bound(all(v),l);
            auto lbr = lower_bound(all(v),r);
            if(lbl != v.end() && lbr != v.end()) {
                bool check = false;
                if(*lbl > l || *lbr > r) check = true;
                else{
                    if(lbr-lbl < r - l) check = true;
                }
                
                if(check) cout << 1;
                else cout << 0;
            }
            else cout << 1;
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