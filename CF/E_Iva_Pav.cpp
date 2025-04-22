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
    int n;
    cin >> n;
    vector<int> v(n+1);
    for(int i = 1; i <= n; i++){
        cin >> v[i];
    }

    int a[31][n+1];

    for(int i = 0; i < 31; i++){
        a[i][0] = 0;
        for(int j = 1; j <= n; j++){
            a[i][j] = ((1LL << i) == ((1LL << i) & v[j]));
            a[i][j] += a[i][j-1];
        }
    }

    int q;
    cin >> q;
    while(q--){
        int l, k;
        cin >> l >> k;

        int lo = l;
        int hi = n;

        int ans = -1;

        while(hi >= lo){
            int mid = (lo + hi)/2;
            int sum = 0;
            for(int i = 0; i < 31; i++){
                if((mid <= n) && (a[i][mid] - a[i][l-1] == (mid - l + 1))) sum += (1LL << i);
            }

            if(sum >= k) {
                ans = mid;
                lo = mid + 1;
            }
            else hi = mid - 1;
        }

        cout << ans << " ";
    }

    
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