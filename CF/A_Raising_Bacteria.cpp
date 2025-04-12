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
    int x, ans = 0;

    while(n!=0){
        x = log2(n);
        n = n-pow(2,x);
        ans++;
    }
    cout << ans << nl;
    // if(pow(2,x) == n) cout << 1 << nl;
    // else cout << x+1 << nl;
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