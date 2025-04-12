#include<bits/stdc++.h>
using namespace std;

#define ll         long long
#define ff         first
#define ss         second
#define pb         push_back
#define nl         '\n'e
#define all(a)     (a).begin(),(a).end()

void solve(){
    int n;
    cin >> n;
    bool check  = false;
    if((n%4 == 0)  or  (n%7 == 0)  or  (n%47 == 0) or (n%74 == 0) or (n%474 == 0) or (n%744 == 0) or (n%477 == 0) or (n%747 == 0) or (n%447 == 0) or (n%774 == 0) ) check = true;

    if(check) cout << "YES" << nl;
    else cout << "NO" << nl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}