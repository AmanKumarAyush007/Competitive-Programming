#include<bits/stdc++.h>
using namespace std;

#define int        long long
#define ff         first
#define ss         second
#define pb         push_back
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()

void solve(){
    int n;
    cin >> n;
    int x = 0;
    int i = 1;
    while(abs(x) < n){
        if(i%2 != 0) x += 2*i-1;
        else x -= 2*i-1;
        i++;
    }
    if(i%2 == 0) cout << "Kosuke" ;
    else cout << "Sakurako";
    cout << nl;
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