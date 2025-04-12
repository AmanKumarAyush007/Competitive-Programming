#include<bits/stdc++.h>
using namespace std;

#define ll         long long
#define ff         first
#define ss         second
#define pb         push_back
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()

ll sum(ll n){
    return (n*(n+1))/2;
}
ll ap_sum(ll n,ll a){
    int last = a-(n-1);
    return n*(a+last)/2;
}

void solve(){
    ll n,a,b;
    cin>>n>>a>>b;
    ll start = max(a,b);
    ll ans = 0;

    if(a>=b) cout<<n*a<<nl;
    else{
        if(n>(b-a+1)){
            ll ans = sum(b) - sum(a-1) + (a*(n-(b-a+1)));
            cout<<ans<<nl;
        }
        else{
            ll ans = ap_sum(n,b);
            cout<<ans<<nl;
        }
    }


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