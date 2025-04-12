#include<bits/stdc++.h>
using namespace std;

#define int        long long
#define ff         first
#define ss         second
#define pb         push_back
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()



void solve(){
    int b,c,d;
    cin >> b >> c >> d;

    int a = (b|c) ^ d;

    if(((b|a) - (a&c)) == d) cout << a << nl; 
    else cout << -1 << nl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}