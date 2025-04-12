#include<bits/stdc++.h>
using namespace std;

#define ll         long long
#define ff         first
#define ss         second
#define pb         push_back
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()

void solve(){
    ll n,x;
    cin >> n >> x;
    ll a[n];
    ll ans = 0;

    for(auto &i : a) cin >> i;

    ll total = 0; 
    sort(a,a+n,greater<int>());


    for(int i = 0; i < n; i++){
        total += a[i];
        if(total < (i+1)*x) break;
        ans = i+1;
    }

    cout << ans << nl;
    

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