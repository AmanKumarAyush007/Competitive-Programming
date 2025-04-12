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
    int a[n][n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }

    int sum = 0;
    for(int i = 0; i < n; i++){
        int j = i;
        int k = 0;
        int mx = 0;
        while(j < n){
            int ele = a[j++][k++];
            if(ele < 0) mx = max(mx,abs(ele));
        }
        sum += mx;
    }

    for(int j = 1; j < n; j++){
        int i = j;
        int k = 0;
        int mx = 0;
        while(i < n){
            int ele = a[k++][i++];
            if(ele < 0) mx = max(mx,abs(ele));
        }
        sum += mx;
    }
    
    
    cout << sum << nl;
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