#include<bits/stdc++.h>
using namespace std;

#define ll         long long
#define ff         first
#define ss         second
#define pb         push_back
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()

void solve(){
    int n;
    cin >> n;
    ll mx = LLONG_MAX;
    ll a[n];
    for(auto &i : a){
        cin >> i;
        mx = max(mx,i);
    }
    ll st = 2;
    set<ll> s;
    ll ans = 0;
    while(st<=mx){
        for(ll i = 0; i < n; i++){
            s.insert(a[i]%st);
        }
        if(s.size() == 2){
            ans = st;
            break;
        }
        else{
            s.clear();
            st=st*2;
        }
    }

    cout << ans << nl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}