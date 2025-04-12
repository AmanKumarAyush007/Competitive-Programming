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

    int a[n];
    
    for(auto &i : a) cin >> i;

    sort(a,a+n);

    int time = 0;


    if(n <= 2) time = a[0];
    else time = (n-2) * 2 * a[0] + a[0];

    if(k >= time) cout << "YES";
    else cout << "NO";

    cout << nl;
}

signed main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    #ifndef ONLINE_JUDGE
    // freopen("error.txt", "w", stderr);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++){
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}