#include<bits/stdc++.h>
using namespace std;

#define int        int64_t
#define ff         first
#define ss         second
#define pb         push_back
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()
#define inp(v)     for(auto& x : v) cin >> x


void solve(){
    int n;
    cin >> n;
    bool ck = false;
    for(int i = 2; i <= 1000; i++){
        int sm = 1+i+i*i;
        if(sm > n) break;
        int j = 3;
        while(sm < n){
            sm += pow(i,j);
            j++;
        }
        if(sm == n) {
            ck = true;
            break;
        }
    }
    cout << (ck ? "YES\n" : "NO\n");
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