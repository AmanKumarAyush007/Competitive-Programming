#include<bits/stdc++.h>
using namespace std;

#define ll         long long
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
    int b[n+2];
    b[0] = -1;
    for(int i = 1; i < n+1; i++){
        b[i] = 1;
    }
    b[n+1] = -1;

    b[a[0]] = 0;

    int check = 1;

    // cout << n;

    for(int i = 1; i < n; i++){
        
        if(((b[a[i]+1] == 0) or (b[a[i]-1] == 0)) and b[a[i]] ==1) {
            // cout << " !";
            b[a[i]] = 0;
        }
        else {
            check = 0;
            break; 
        }
            // cout << " !";

        
    }

    if(check == 1) cout << "YES" ;
    else cout << "NO" ;
    cout << nl;


    // for(auto &i : b) cout << i << " ";
    // cout << nl;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}