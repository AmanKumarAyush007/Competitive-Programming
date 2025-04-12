#include<bits/stdc++.h>
using namespace std;

#define int        long long
#define ff         first
#define ss         second
#define pb         push_back
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()

int fun(int n){
    return (n*(n-1))/2;
}

void solve(){
    int n;
    cin >> n;
    int m = fun(n);
    int a[m];
    for(auto &i : a) cin >> i;
    sort(a,a+m);
    // for(auto &i : a) cout << i << " ";
    int k = n-1; 
    vector<int> v;

    for(int i = 0; i < m; ){
        int temp = k;
        int curr = 1e9;
        // cout << temp;
        while(temp) {
            curr = min(curr,a[i]);
            temp--;
            i++;
        }
        k--;
        v.pb(curr);
    }
    while(v.size() < n ){
        v.pb(1e9);
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