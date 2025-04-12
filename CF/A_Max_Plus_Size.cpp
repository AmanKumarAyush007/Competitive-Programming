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
    vector<int> v(n);
    for(auto &i : v)cin >> i;
    int mx = INT_MIN;
    int ind;
    for(int i = 0; i < n; i++){
        if(v[i] > mx){
            mx = v[i];
            ind = i;
        }
    }

    if(ind%2 == 0) cout <<  mx+ n/2 + (n == 1 || n%2!=0);
    else {
        for(int i = 0; i < n; i++){
            if(i%2 == 0 && v[i] == mx){
                cout <<  mx+ n/2 + (n == 1 || n%2!=0) << nl;
                return;
            }
        }
        cout << mx + n/2;
    }

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