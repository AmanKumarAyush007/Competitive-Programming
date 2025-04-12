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
    int a[n];
    int sum = 0;
    for(auto &i : a) {
        cin >> i;
        sum += i;
    }

    sort(a,a+n);

    if(n <= 2) cout << -1;
    else{
        int mid = a[n/2];
        cout << max(0LL,(mid*2*n - sum +1));
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