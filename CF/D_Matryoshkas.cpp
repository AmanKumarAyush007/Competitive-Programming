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
    int a[n];
    inp(a);
    map<int,int> mp;
    for(auto &i : a) mp[i]++;
    int ans = 0;
    while(!mp.size() == 0){
        int x = mp.begin()->first;
        while(mp.find(x) != mp.end()){
            mp[x]--;
            if(mp[x] == 0) mp.erase(x);
            x++;
        }
        ans++;    
    }
    cout << ans << nl;
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