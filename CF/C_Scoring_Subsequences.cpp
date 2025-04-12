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
    int a[n];
    inp(a);
    vector<int> ans(n,1);
    for(int i = 1; i < n; i++){
        int lo = 0;
        int hi = i;
        int id = 0;

        while(lo <= hi){
            int mid = (lo+hi)/2;
            if(a[mid]/(i+1-mid) >= 1) {
                id = mid;
                hi = mid - 1;
            }
            else lo = mid + 1;
        }

        ans[i] = i-id+1;
    }

    for(auto &i : ans)cout << i << " ";
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