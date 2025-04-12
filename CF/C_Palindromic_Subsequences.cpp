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
    vector<int> v(n,1);
    int k = 2;
    if(n == 6){
        v[0] = 1;
        v[2] = 2;
        v[3] = 3;
        v[5] = 2;
    }
    else{
        v[1] = k;
        v[n-2] = k++;
        v[2] = k;
        v[n-1] = k++;
        for (int i = 3; i < n - 3; i++){
            v[i] = k++;
        }
    }
    for(auto &i : v) cout << i << " ";


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