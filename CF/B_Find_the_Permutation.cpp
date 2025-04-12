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
    
    vector < string> v;
    int k = n;
    while(k--){
        string s;
        cin >> s;
        v.pb(s);
    }
    // deque<int> dq;
    // string ans = '1';
    vector<int> ans;
    int c = 1;
    ans.pb(c++);
    for(int i = 0; i < n-1; i++){
        ans.pb(c++);
        if(v[i][i+1] == '0') {
            
        }
    }
    vector<int> ans(all(dq));

    for(auto &i : dq) cout << i << " ";



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