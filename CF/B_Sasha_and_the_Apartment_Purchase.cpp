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
    int n, k;
    cin >> n >> k;
    int a[n];
    inp(a)


    int mn = *min_element(a,a+n);
    int mx = *max_element(a,a+n);


    for(int i = mn; i <= mx; i++){
        int ans = 0;
        vector<int> v;
        for(int j = 0; j < n; j++){
            v.pb(abs(i - a[j]));
        }
       ans += accumulate(all(v),0LL);
       sort(all(v));
       int mn = v[0];
       map<int,int> mp;
       for(int j = 0; j < v.size(); j++){
           mp[mn]++;
       }
       cout << mp[mn] << nl;


        // cout << "ansPre -> " << ans << nl;
        // cout << i << " -> ";
    //    for(int j = 1; j <= k; j++){
    //        ans -= v[n-j];
    //     //    cout << v[n-j];
    //    }
        // cout << ans << "\n" ;
        // cout << "ansPost -> " << ans << nl;
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