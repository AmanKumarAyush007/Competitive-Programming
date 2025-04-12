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
    if(n == 0) cout << 1 << nl;
    else if(n%4 == 0) cout << 6 << nl;
    else if(n%4 == 3) cout << 2 << nl;
    else if(n%4 == 2) cout << 4 << nl;
    else cout << 8 << nl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}