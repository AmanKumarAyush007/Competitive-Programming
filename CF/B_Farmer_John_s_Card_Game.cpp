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
    int n,m;
    cin >> n >> m;
    vector<int> v;
    vector<vector<int>> vi;
    for(int i = 0; i < n; i++){
        vector<int> vv;
        for(int j = 0; j < m; j++){
            int ele; cin >> ele;
            vv.pb(ele);
        }
        sort(all(vv));
        vi.pb(vv);
        // for(auto &ie : vv) cout << ie << " "; 
        v.pb(vv[0]);
    }
    vector<int> ans = v;
    sort(all(v));
        // for(auto &ie : v) cout << ie << " "; 
    

    for(int i = 0; i < n; i++){
        if(v[i]!=i) {
            cout << -1 << nl;
            return;
        }
    }

    vector<int> sol;
    // int k = 0;
    for(int i = 0; i < n; i++){
        auto it = find(all(ans),i);
        sol.pb((it - ans.begin()));
    }
    // for(auto &i : sol) cout << i << " ";
    // for(auto &i : vi){
    //     for(auto &ele : i) cout << ele << " ";
    //     cout << nl;
    // }
    int k = 0;
    for(int j = 0; j < m; j++){
        for(auto &i : sol) {
            // cout << vi[i][j] << " ";
            if(vi[i][j] == k) k++;
            else {
                cout << -1 << nl;
                return;
            }
        }
    }

    for(auto &i : sol) cout << i+1 << " ";




    


    

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