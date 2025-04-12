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
    map<int,int> mp;
    vector<vector<int>> v;
    while(n--){
        int k; cin >> k;
        vector<int> vv;
        while(k--){
            int ele;
            cin >> ele;
            vv.pb(ele);
            mp[ele]++;
        }
        v.pb(vv);
    }

    bool flag;
    for(int i = 0; i < v.size(); i++){
        flag = true;
        for(int j = 0; j < v[i].size(); j++){
            if(mp[v[i][j]] <= 1){
                flag = false;
                break;
            }
        }

        if(flag) break;
    }

    cout << ((flag) ? "Yes" : "No");
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