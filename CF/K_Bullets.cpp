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
    int a[n+1];
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    map<int,int> vp;

    for(int i = 1; i <= n; i++){
        vp[a[i]] = i;
    }

    int ans = 1;


    for(int i = 1; i < n; i++){
        if(vp[i] > vp[i+1]) continue;
        else ans++;
    }
    
    cout <<ans<< nl;
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