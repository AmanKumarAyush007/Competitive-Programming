#include<bits/stdc++.h>
using namespace std;

#define int        int64_t
#define ff         first
#define ss         second
#define pb         push_back
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()

void solve(){
    int n,k;
    cin >> n >> k;


    if(n == k){
        if(n == 1){
            cout << 1 << nl << 1;
        }
        else cout << -1;
    }
    else if(k==1) cout << -1;
    else{
        cout << 3 << nl;
        if((k-1)%2 == 1) cout << 1 << " " << k << " " << k+1;
        else cout << 1 << " " << k-1 << " " << min(n,k+2);
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