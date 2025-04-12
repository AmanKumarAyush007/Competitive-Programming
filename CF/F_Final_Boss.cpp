#include<bits/stdc++.h>
using namespace std;

#define int        int64_t
#define ff         first
#define ss         second
#define pb         push_back
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()
#define inp(v)     for(auto& x : v) cin >> x

bool check(int h,vector<int>& a,vector<int>& c, int mid){
    int val = 0;
    int n = a.size();
    for(int i = 0; i < n; i++){
        if(((1e18 -  val)/(a[i])) < ((mid/c[i]) + (mid%c[i] != 0))) return true;
        val += a[i]* ((mid/c[i]) + (mid%c[i] != 0));
    }
    return val >= h;
}


void solve(){
    int h,n;
    cin >> h >> n;
    vector<int> a(n);
    for(auto &i : a) cin >> i;
    vector<int> c(n);
    for(auto &i : c) cin >> i;

    int hi = 1e18;
    int lo = 0;
    int ans = -1;

    while(lo <= hi){
        // cout << lo << " " << hi << nl;
        int mid = hi - ((hi-lo)/2);
        if(check(h,a,c,mid)){
            ans = mid;
            hi = mid-1;
        }
        else lo = mid + 1; 
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