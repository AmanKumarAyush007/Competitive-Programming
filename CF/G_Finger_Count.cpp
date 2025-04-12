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
    int  a[n];
    int sum = 0;
    
    for(auto &i : a) {
        cin >> i;
        sum += i;

    }

    int ans = 0;

    for(int i = 1; i <= 5; i++){
        if((sum + i) % (n+1) != 1) ans++;
    }

    cout << ans << nl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}