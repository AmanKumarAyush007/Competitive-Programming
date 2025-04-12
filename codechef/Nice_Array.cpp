#include<bits/stdc++.h>
using namespace std;

#define int        int64_t
#define ff         first
#define ss         second
#define pb         push_back
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()

void solve(){
    int n,k;
    cin >> n >> k;

    vector<int> v(n);
    for(auto &i : v) cin >> i;

    bool ck =  false;
    int sum = 0;
    int c = 0;


    for(int i = 0; i < n; i++){
        sum += floor((v[i]*1.0)/k);
        if(v[i] % k != 0) c++;
    }
    if(sum <= 0 && sum >= -c) cout << "YES" <<nl;
    else cout << "NO\n"; 
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