#include<bits/stdc++.h>
using namespace std;

#define ll         long long
#define ff         first
#define ss         second
#define pb         push_back
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()


void solve(){
    int n,x;
    cin >> n >> x;
    
    if(n%2 == 0) n++;
    
    int ans = 0;
    ans = (x-n+2)/4;

    cout << ans <<nl;
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