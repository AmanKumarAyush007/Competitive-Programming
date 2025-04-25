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

map<int,int> mp;

bool check(int mid, int n){
    int task_req = 0;
    int task_rem = 0;
    
    for(int i = 1; i <= n; i++){
        if(mp[i] >= mid) task_req += mp[i] - mid;
        else task_rem += (mid - mp[i])/2;
    }

    return task_rem >= task_req;
}


void solve(){
    int n , m;
    cin >> n >> m;
    vector<int> v(m);
    inp(v)

    for(auto &i : v) mp[i]++;

    int hi = 2*m;
    int lo = 1;

    int ans = 1;
    while(hi >= lo){
        int mid = (lo+hi)/2;
        if(check(mid, n)){
            ans = mid;
            hi = mid-1;
        }
        else lo = mid + 1;
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
        mp.clear();
    }
    return 0;
}