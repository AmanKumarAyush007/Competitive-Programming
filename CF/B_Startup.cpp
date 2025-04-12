#include<bits/stdc++.h>
using namespace std;

#define int        int64_t
#define ff         first
#define ss         second
#define pb         push_back
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()

void solve(){
    int n,k;
    cin >> n >> k;

    int q = k;
    map<int,int> mp;

    while(q--){
        int x,y;
        cin >> x >> y;
        // if(mp.find(x) == mp.end()) mp[x] = 0;
        mp[x] += y;
    }

    vector<int> v;

    for(auto &[a,b] : mp){
        v.pb(b);
    }
    sort(all(v),greater<int>());

    // for(auto &i : v) cout << i << " ";
    int i = 0;
    int ans = 0;
    int m = v.size();

    while(n>0 && i < m){
        ans += v[i++];
        n--;
    }


    cout<< ans << nl;
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