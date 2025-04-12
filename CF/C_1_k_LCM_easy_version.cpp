#include<bits/stdc++.h>
using namespace std;

#define ll         long long
#define ff         first
#define ss         second
#define pb         push_back
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()

void solve(){
    int n,k;
    cin >> n >> k;
    if(n%3 == 0) cout << n/3 << " " << n/3 << " " << n/3 << nl;
    else if(n%2 != 0) cout << n/2 << " " << n/2 << " " << 1 << nl;
    else if(n%4 == 0) cout << n/2 << " " << n/4 << " " << n/4 << nl;
    else cout << (n-2)/2 << " " << (n-2)/2 << " " << 2 << nl;
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