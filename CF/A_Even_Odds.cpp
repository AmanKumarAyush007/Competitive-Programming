#include<bits/stdc++.h>
using namespace std;

#define ll         long long
#define ff         first
#define ss         second
#define pb         push_back
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()

void solve(){
    ll n,k;
    cin >> n >> k;
    // cout << n/2;
    if(k <= (n/2 + (n%2 != 0))) cout << 2*k-1 << nl;
    else cout << (k - (n/2 + (n%2 != 0)))*2 << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}