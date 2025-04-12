#include<bits/stdc++.h>
using namespace std;

#define int        long long
#define ff         first
#define ss         second
#define pb         push_back
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()

void solve(){
    int n,m;
    cin >> n >> m;


    vector<pair<int,int>> vp;

    int ans = 0;

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            if(i+j <= 0) continue;
            else{
                int k = i*i + j*j;
                int temp = sqrt(k);
                if(temp * temp != k) {
                    vp.pb({i,j});
                    ans++;
                }
            }
        }
    }
    cout << ans << nl;
    for(auto &[a,b] : vp) cout << a <<" "<< b << nl;;

    
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}