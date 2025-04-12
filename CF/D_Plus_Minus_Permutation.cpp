#include<bits/stdc++.h>
using namespace std;

#define ll         long long
#define ff         first
#define ss         second
#define pb         push_back
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()

ll fst(ll n){
    return (n*(n+1))/2;
}
ll lst(ll n, ll x){
    return fst(n) - fst(n-x);
}
void solve(){
    ll n,x,y;
    cin >> n >> x >> y;

    ll Lcm = lcm(x,y);
    ll com = n/Lcm ;

    ll f = n/x - com;
    ll l = n/y - com;

    cout << lst(n,f) - fst(l);
    
    cout << nl;  
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