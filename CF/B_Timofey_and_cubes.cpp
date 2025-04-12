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
    int a[n];
    for(auto &i : a) cin >> i;
    
    for(int i = 0; i < n/2 ; i++){
        if(i % 2 == 0) swap(a[i],a[n-1-i]);
    }

    for(auto &i : a) cout << i << " ";
    cout << nl;
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