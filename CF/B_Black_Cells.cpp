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
    cin >> n;
    vector<int> v(n);
    inp(v);
    if(n == 1 || n == 2){
        if(n == 1) cout << 1 << nl;
        else cout << v[n-1] - v[0] << nl;
        return;
    }
    if(n%2 == 0){
        int diff = -1;
        for(int i = 0; i < n-1; i+=2){
            diff = max(v[i+1] - v[i],diff);
        }
        
        cout <<diff<< nl;
        return;
    }
    map<int,int>mp;
    for(int i = 0; i < n-1; i++){
        mp[v[i+1] - v[i]]++;
    }
    
    if(mp.size() == 1) {
        auto it = mp.begin();
        cout << it->ff << nl;
        return;
    }
    auto it = mp.rbegin();
    if(it->ss != 1) {
        cout << it->ff;
    }
    else{
        auto t = mp.end();
        t--; 
        mp.erase(t);
        auto k = mp.rbegin();
        cout << k -> ff;
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