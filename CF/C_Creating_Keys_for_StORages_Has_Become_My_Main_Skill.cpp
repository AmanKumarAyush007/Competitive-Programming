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
    int n,k;
    cin >> n >> k;
    vector<int> v;
    if(n == 1){
        cout << k << nl;
        return;
    }
    else{
        for(int i = 0; i <= k; i++){
            if(n-v.size() == 1) break;
            if((i | k) == k){
                v.pb(i);
            }
            else break;
        }
        int d = v[0];
        for(int i = 1; i < v.size(); i++){
            d |= v[i];
        }
        if(n-v.size() == 1){
            int e = v[v.size() - 1];
            if(d != k){
                if((((e+1)|k) == k) && (((e+1)|d) == k)) v.pb(e+1);
                else v.pb(k);
            }
            else{
                if((((e+1)|k) == k)) v.pb(e+1);
                else v.pb(k);
            }
        }
        
        while(n-v.size()) {
            v.pb(k);
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