#include<bits/stdc++.h>
using namespace std;

#define int        long long
#define ff         first
#define ss         second
#define pb         push_back
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()

void solve(){
    int n;
    cin >> n;
    int k; cin >> k;

    int f = n;
    int l = f-k+1;

    int cnt = 0;

    if(f%2 == 0 and l%2 == 0) cnt = (f-l)/2;
    else cnt = 1 + (f-l)/2;

    if(cnt%2 == 0) cout << "YES";
    else cout << "NO";
    
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