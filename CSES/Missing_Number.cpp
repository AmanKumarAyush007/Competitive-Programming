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
    int a[n-1];
    for(int i = 0; i < n-1; i++){
        cin >> a[i];
    }
    sort(a,a+n-1);
    
    if(a[n-2] != n) cout << n;
    else if(n==2) cout << 1;
    else{
        for(int i = 0; i < n-2; i++){
            if(a[i] != a[i+1]-1){
                cout << a[i]+1;
                break;
            }
        }
    }
    
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