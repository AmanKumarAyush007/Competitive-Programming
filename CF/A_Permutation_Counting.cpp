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
#define sm(v)      accumulate(all(v),0LL)
#define inp(v)     for(auto& x : v) cin >> x;
#define setbit(x)  __builtin_popcountll(x)

bool check(int x, vector<int> &v, int k){
    for(int i = 0; i < v.size(); i++){
        if(v[i] < x){
            int req = x - v[i];
            if(k < req) return false;
            else k -= req;
        }
    }
    return true;
}


void solve(){
    int n , k;
    cin >> n >> k;
    vector<int> v(n);
    inp(v)

    int hi = 1e18;
    int lo = 1;
    int ans = 1;

    while(lo <= hi){
        int mid = hi - ((hi - lo)/2);
        if(check(mid,v,k)){
            ans = mid;
            lo = mid + 1;
        }
        else hi = mid - 1;
    }


    for(int i = 0; i < n; i++){
        if(k <= 0) break;
        if(v[i] < ans && ( k >= ans - v[i] )) {
            k -= (ans - v[i]);
            v[i] = ans;
        }
    }


    sort(all(v));
    if(k >= 1) {
        for(int i = 0; i < n; i++){
            if(k >= 1){
                v[i]++;
                k--;
            }
            else break;
        }
    }

    sort(all(v));

    auto it = upper_bound(all(v),ans);
    int ex = it - v.begin();

    cout << (ans*n) - (ex-1) ;
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