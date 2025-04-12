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
    cin>>n;
    vector<ll>a;
    vector<ll>b;
    for(ll i = 0; i < n; i++){
        ll ele;
        cin>>ele;
        a.pb(ele);
    }
    for(ll i = 0; i < n+1; i++){
        ll ele;
        cin>>ele;
        b.pb(ele);
    }
    // vector<ll> diff;
    // for(ll i = 0; i < n; i++){
    //     ll ele = abs(a[i]-b[n]);
    //     diff.pb(ele);
    // }
    // auto it = min_element(diff.begin(),diff.end());
    // ll minIndex = distance(diff.begin(), it);
    // int mn = *it;
    // // cout<<minIndex<<nl;
    // // for(int i = 0; i < n; i++){
    // //     cout<<diff[i]<<" ";
    // // }
    // // cout<<nl;



    // a.pb(a[minIndex]);

    ll mn = INT_MAX;
    for(int i = 0 ; i < n; i++){
        mn = min({abs(b[n]-a[i]), abs(b[n]-b[i]), mn});
    }
    ll ans = 1;
    ll d = 0;
    int check = 0;
    for(ll i = 0; i < n; i++){
        if(a[i] == b[n] || b[i]==b[n]) check = 1;
        else if(a[i] >= b[n] && b[i] <= b[n]){
            check = 1;
        }
        else if(a[i] <= b[n] && b[i] >= b[n]){
            check = 1;
        }
        
        ans+=abs(a[i]-b[i]);
    }
    if(check == 1) cout<<ans<<nl;
    else cout<<ans+mn<<nl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}