#include<bits/stdc++.h>
using namespace std;

#define ll         long long
#define ff         first
#define ss         second
#define pb         push_back
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()

void solve(){
    ll n;
    cin >> n;
    ll a[n];
    for(ll i = 0; i < n; i++){
        cin>>a[i];
    }
    
    ll mx = INT_MIN,sum = 0, ans = 0;
    for(ll i = 0; i < n; i++){
        sum += a[i];
        mx = max(mx,a[i]);
        if(sum == 2*mx) ans++;
    }
    cout<<ans<<nl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}