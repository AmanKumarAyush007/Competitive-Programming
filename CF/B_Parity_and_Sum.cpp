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
    vector<ll> v(n);
    vector<ll> e;
    ll omax = 0;
    for(auto &i : v){
        cin >> i;
        if(i % 2 == 0) e.pb(i);
        else {
            omax = max(i,omax);
        }
    }
    if(e.size() == n || e.size() == 0) cout << 0 ;
    else{
        ll ck = 0;
        sort(all(e));
        for(int i = 0; i < e.size(); i++){
            if(e[i] < omax) {      //since e[i] is even and omax is always odd therefore e[i] can never be same or equal
                omax += e[i]; 
            }
            else{
                ck = 1;
            }
        }

        cout << e.size() + ck ;
    }

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