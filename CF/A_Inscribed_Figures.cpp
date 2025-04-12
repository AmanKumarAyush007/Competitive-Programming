#include<bits/stdc++.h>
using namespace std;

#define int        int64_t
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
    int ans = 0;
    for(int i = 0; i < n-1; i++){
        if(a[i] == 1 && a[i+1] == 2) ans+=3;
        else if(a[i] == 2 && a[i+1] == 1) ans+=3;
        else if(a[i] == 3 && a[i+1] == 1) ans+=4;
        else if(a[i] == 1 && a[i+1] == 3) ans+=4;
        else{
            cout << "Infinite" << nl;
            return;
        }
    }
    for(int i = 0; i < n-2; i++){
        if(a[i] == 3 && a[i+1] == 1 && a[i+2] == 2) ans--;
    }

    cout<<"Finite\n" << ans << nl;
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