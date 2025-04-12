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
    
    vector<int> f(n+1,0), f1(n+1,0);

    for(int i = 0; i < n; i++){
        int x,y;
        cin >> x >> y;

        if(y) f[x]++;
        else f1[x]++;
    }

    ll ans = 0;

    for(int i = 0; i <= n; i++){
        
        if(f[i] && f1[i]) ans += n-2;

        if(i > 0 && i < n){
            if(f[i] && f1[i-1] && f1[i+1]) ans++;
            if(f1[i] && f[i-1] && f[i+1]) ans++;
        }
    }

    cout << ans ;
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