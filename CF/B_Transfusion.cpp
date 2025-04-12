#include<bits/stdc++.h>
using namespace std;

#define int        int64_t
#define ff         first
#define ss         second
#define pb         push_back
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()
#define inp(v)     for(auto& x : v) cin >> x
#define sm(v)      accumulate(all(v),0LL)


void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    inp(a);
    int alt = 0;
    int cnt = 0;
    int rest = 0;
    for(int i = 0; i < n; i++){
        if(i%2 == 0) alt += a[i], cnt++;
        else rest += a[i];
    }
    
    cout << ((((alt/cnt) == (rest/(n - cnt)) && (sm(a)%n == 0 && alt/cnt == sm(a)/n))) ? "YES" : "NO");
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