#include<bits/stdc++.h>
using namespace std;

#define int        int64_t
#define ff         first
#define ss         second
#define pb         push_back
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()

void solve(){
    int n,x,y; 
    cin >> n >> x >> y;
    int a[n];
    for(auto &i : a) cin >> i;
    int ans = 0;

    map<pair<int,int>,int> mp;
    for(auto &i : a){
        int X = (x - i%x) % x;
        int Y = i % y;
        ans += mp[{X,Y}];
        mp[{i%x,i%y}]++;
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