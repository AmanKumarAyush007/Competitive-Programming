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
    int a[n];
    for(auto &i : a) cin >> i;
    int ans = 0, curr = 0;
    for(int i = 0; i < n; i++){
        if(a[i]>=k){
            curr += a[i];
            a[i] = 0;
        }
        else if(a[i] == 0 && curr > 0){
            curr -= 1;
            a[i] += 1;
            ans++;
        }
    }
    cout << ans;
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