#include<bits/stdc++.h>
using namespace std;

#define int        int64_t
#define ff         first
#define ss         second
#define pb         push_back
#define inf        LLONG_MAX
#define hell       LLONG_MIN
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()
#define inp(v)     for(auto& x : v) cin >> x
#define sm(v)      accumulate(all(v),0LL)

bool check (vector<int> &v, int mid, int k){
    int n = v.size();
    int res = 0;
    for(int i = 0; i < n; i++){
        if( ((v[i] +(2*mid)) * (v[i] + (2*mid))) > 1e18 || ((v[i] +(2*mid)) * (v[i] + (2*mid))) < 0 || (res + ((v[i] +(2*mid)) * (v[i] + (2*mid)))) > 1e18 || (res + ((v[i] +(2*mid)) * (v[i] + (2*mid)))) < 0) return true;
        res += ((v[i] +(2*mid)) * (v[i] + (2*mid)));
    }
    return res >= k;
}


void solve(){
    int n,k;
    cin >> n >> k;
    vector<int> v(n);
    inp(v);
    // cout << check(v,1);

    int hi = 1e9;
    int lo = 1;
    int ans = 1;


    while(hi >= lo){
        int mid = hi - ((hi - lo)/2);
        if(check(v,mid,k)){
            ans = mid;
            hi = mid-1;
            
        }
        else lo = mid+1;
    }

    cout << ans;

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