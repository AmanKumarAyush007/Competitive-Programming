#include<bits/stdc++.h>
using namespace std;

#define ll         long long
#define ff         first
#define ss         second
#define pb         push_back
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()


void solve(){
    int a,b;
    cin >> a >> b;
    ll ans = 0;
    for(int i = 1; a <= b; i++){
        a += i;
        ans++;
    }

    cout << ans;
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