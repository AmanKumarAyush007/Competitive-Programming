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
    ll a[n],pre[n];
    for(auto &i : a) cin >> i;
    for(ll i = 0; i < n; i++){
        if(i == 0) pre[i] = a[i];
        else pre[i] = pre[i-1] + a[i]; 
    }

    string s;
    cin >> s;
    vector<ll> l,r;
    for(ll i = 0; i < n; i++){
        if(s[i] == 'L') l.pb(i);
        if(s[i] == 'R') r.pb(i);
    }

    sort(all(l));
    sort(all(r));

    ll i = 0;
    ll j = r.size()-1;

    vector<pair<ll,ll>> vp;

    while(i < l.size() && j >= 0){
        if(l[i] < r[j]) {
            vp.pb({l[i],r[j]});
            i++;
            j--;
        }
        else break;
    }
    ll ans = 0;
    for(auto &[a,b] : vp){
        if(a!=0) ans += pre[b] - pre[a-1];
        else ans += pre[b];
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