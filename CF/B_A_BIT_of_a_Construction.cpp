#include<bits/stdc++.h>
using namespace std;

#define int        long long
#define ff         first
#define ss         second
#define pb         push_back
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()


void solve(){
    int n,k;
    cin >> n >> k;
    if(n == 1) cout << k ;
    else{
        int lg = log2(k);
        int sum = (1LL << lg)-1;
        cout << sum << " " << k - sum << " ";
        for(int i = 0; i < n-2; i++) cout << 0 << " " ;
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