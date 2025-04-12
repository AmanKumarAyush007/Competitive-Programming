#include<bits/stdc++.h>
using namespace std;

#define int        int64_t
#define ff         first
#define ss         second
#define pb         push_back
#define inf        LLONG_MAX
#define hell       LLONG_MIN
#define nl         '\n'
#define setbit(x)  __builtin_popcountll(x)
#define all(a)     (a).begin(),(a).end()
#define sm(v)      accumulate(all(v),0LL)
#define inp(v)     for(auto& x : v) cin >> x


int nth(int n) {
    return n*(n+1)/2;
}


void solve(){
    int k,x;
    cin >> k >> x;

    int ans = 0;

    if(x >= k*k) ans = (2*k)-1;
    else if (x <= ((k*(k+1))/2)){
        int lo = 1;
        int hi = k;

        while(lo <= hi){
            int mid = (lo+hi)/2;

            if(nth(mid) >= x){
                ans = mid;
                hi = mid-1;
            }
            else lo = mid+1;
        }
    }
    else {
        int hi = k-1;
        int lo = 1;

        int rest = x - nth(k);

        while(lo <= hi){
            int mid = (lo+hi)/2;
            if(((mid*((2*(k-1)) - (mid - 1)))/2) >= rest){
                ans = k + mid;
                hi = mid - 1;    
            }
            else lo = mid + 1;

        }
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