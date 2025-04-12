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
    int n,x,y;
    cin >> n >> x >> y;

    vector<int> v(n);
    inp(v);

    int sum = 0;
    for(auto &i : v) sum += i;

    x = sum - x;
    y = sum - y;
    if(x > y)swap(x,y);

    sort(all(v));

    int ans = 0;

    for(int i = 0; i < n-1; i++){
        int l = max(v[i],x-v[i]);
        int r = min(v[n-1],y-v[i]);
        auto lb = lower_bound(v.begin() + (i+1),v.end(),l);
        auto it = upper_bound(v.begin() + (i+1),v.end(),r);
        it--;
        ans += max(0LL,it-lb+1);
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