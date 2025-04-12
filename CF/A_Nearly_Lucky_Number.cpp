#include<bits/stdc++.h>
using namespace std;

#define ll         long long
#define ff         first
#define ss         second
#define pb         push_back
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()

void solve(){
    ll n;
    cin >> n;
    int count = 0;
    while(n>0){
        int dig = n%10;
        
        if(dig == 4 or dig == 7){
            count++;
        }
        n=n/10;
    }
    if(count == 4 or count == 7) cout << "YES" << nl;
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