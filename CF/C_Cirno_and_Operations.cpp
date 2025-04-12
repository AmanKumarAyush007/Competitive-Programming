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
    vector<int> v(n);
    inp(v);
    vector<int> ans = v;
    int sum = 0;
    for(auto &i : v) sum += i;
    while(ans.size() != 1){
        int x = 0;
        int k = ans.size();
        vector<int> p;
        for(int i = 0; i < k-1; i++){
            int ele = ans[i+1] - ans[i];
            x += ele;
            p.pb(ele);
        }
        ans = p;
        sum = max(sum,abs(x));
        
    }
    cout<< sum << nl;
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