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

bool check(vector<int> &v, int k, int mx){
    int n = v.size();
    int tot = 0;
    for(int i = 0; i < n; i++){
        tot += max(0LL,k-v[i]);
    }
    return mx >= tot;
}

void solve(){
    int n,k;
    cin >> n >> k;
    vector<int> v(n);
    inp(v);

    int hi = 1e10;
    int lo = 1;
    int ans = 1;

    while(hi >= lo){
        int mid = (lo+hi)/2;
        if(check(v,mid,k)){
            ans = mid;
            lo = mid + 1;
        }
        else hi = mid - 1;
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