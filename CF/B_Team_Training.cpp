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


void solve(){
    int n,k;
    cin >> n >> k;
    vector<int> v(n);
    inp(v)

    sort(all(v));

    int ans = 0;

    int ind = n;

    auto it = lower_bound(all(v),k);
    if(it != v.end()) {
        ind = it - v.begin();
        ans += n - ind;
    }

    ind--;
    if(ind < 0){
        cout << n <<nl;
        return;
    }

    // cout << ind;
    // cout << nl;

    // for(auto &i : v) cout << i << " ";
    // cout << nl;


    
    int curr = 0;
    int mn = inf;
    int cnt = 1;
    for(int i = ind; i >= 0; i--){
        if(curr >= k){
            // cout << mn << " ";
            ans++;
            curr = v[i];
            mn = v[i];
            cnt = 2;
        }
        else{
            mn = min(mn,v[i]);
            curr = cnt * mn;
            cnt++;
        } 
    }
    
    if(curr >= k) ans++;

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