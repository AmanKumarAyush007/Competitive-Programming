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
#define inp(v)     for(auto& x : v) cin >> x
#define sm(v)      accumulate(all(v),0LL)


pair<int, int> sol(int N, int k) {
    if (k <= 0 || N <= k) {
        return {-1, -1}; 
    }

    pair<int, int> result = {-1, -1};
    long long maxProduct = -1;
    
    for (int a = 1; a + k <= N; a++) {
        int b = a + k;
        
        if (gcd(a, b) == 1) {
            long long currentProduct = (a) * b;
            
            if (currentProduct > maxProduct) {
                maxProduct = currentProduct;
                result = {a, b};
            }
        }
    }
    
    return result;
}


void solve(){
    int x,y;
    cin >> x >> y;

    pair<int,int> ans = sol(x,y);

    cout << ans.ff << " " << ans.ss;
    
    
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