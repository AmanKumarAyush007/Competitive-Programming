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
    int n,m;
    cin >> n >> m;
    vector<int> a(n),b(m);
    inp(a);
    inp(b);
    sort(all(b));
    for(int i = 0; i < n; i++){
        
        if(i == 0) a[i] = min(b[0]-a[i],a[i]);
        else{
            auto it = lower_bound(all(b),(a[i]+a[i-1]));
            if(it == b.end()) continue;
            int k = *it;
            int p = min(k-a[i],a[i]); 
            int q = max(k-a[i],a[i]);
            if(a[i-1]<=p) a[i] = p;
            else a[i] = q;
        }
    }

    cout << ((is_sorted(all(a))) ? "YES\n" : "NO\n");
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