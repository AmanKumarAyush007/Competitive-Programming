#include<bits/stdc++.h>
using namespace std;

#define int        long long
#define ff         first
#define ss         second
#define pb         push_back
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()

void solve(){
    int n;
    cin >> n;
    // int a[n];
    // for(auto &i : a) cin >> i;
    // for(auto &i : a) cout << i << " ";
    // int pre[n];
    // pre[0] = a[0];
    // for(int i = 1; i < n; i++){
    //     pre[i] = pre[i-1] + a[i];
    // }

    int ans = 0;
    int curr = 0;
    map<int,int> mp;
    mp[0] = 0;
    // for(auto &i : pre) cout << i << " ";
    // for(auto &i : pre) mp[i] = false;

    for(int i = 0; i < n; i++){
        int ele;
        cin >> ele;
        curr += ele;

        if(mp.find(curr) != mp.end()){
            ans++;
            mp.clear();
            mp[0] = 0;
            curr = 0;
        }
        else{
            mp[curr]++;
        }
    }
    // bool k;
    // if(k) cout << 1;

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