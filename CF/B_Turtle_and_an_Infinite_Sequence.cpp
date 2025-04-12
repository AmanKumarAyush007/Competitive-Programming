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
    int n,k;
    cin >> n >> k;
    int ans = n;
    int l = max(0LL,n-k);
    int r = n+k;
    int ind = -1;
    for(int i = 31; i >= 0; i--){
        if(((1LL << i) & l) != ((1LL << i) & r)) {
            ind = i;
            break;
        }
    }
    n |= ((1LL << (ind+1)) - 1); 
    cout << n << nl;
    
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