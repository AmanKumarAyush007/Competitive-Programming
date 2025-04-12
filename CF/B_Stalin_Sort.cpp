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
    for(auto &i : a) cin >> i;

    int ans = n;

    for(int i = 0; i < n; i++){
        int curr = i;
        for(int j = i+1; j < n; j++){
            if(a[j] > a[i]) curr++;
        }
        ans = min(curr,ans);
    }

    
    cout << ans << nl;
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