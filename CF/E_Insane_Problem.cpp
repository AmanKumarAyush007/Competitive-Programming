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
    int k,l1,r1,l2,r2;
    cin >> k >> l1 >> r1 >> l2 >> r2;
    int ans = 0;
    int curr = 1;
    while(curr <= r2){
        int min_x = l2/curr;
        int max_x = r2/curr;
        if(l2 % curr != 0) min_x++;
        min_x = max(min_x,l1);
        max_x = min(max_x,r1);
        ans += max(0LL,max_x - min_x +1);
        curr *= k;
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