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
    int n,k; cin >> n >> k;
    int a[n];
    inp(a);
    map<int,int> mp;
    for(auto &i : a) mp[i]++;
    int ans = mp.size();


    vector<int>v;
    for(auto &[a,b] : mp){
        v.pb(b);
    }
    sort(all(v));

    for(int i = 0; i < v.size(); i++){
        if(k >= v[i]) {
            k-= v[i];
            ans--;
        }
        else break;
    }

    cout << max(1LL,ans) << nl;
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