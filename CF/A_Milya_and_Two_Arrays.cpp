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
    map<int,int>mp,mpb;
    for(int i = 0; i < n; i++){
        int ele;
        cin >> ele;
        mp[ele]++;
    }
    for(int i = 0; i < n; i++){
        int ele;
        cin >> ele;
        mpb[ele]++;
    }

    if(mp.size()*mpb.size() >= 3) cout << "YES\n";
    else cout<< "NO" << nl;
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