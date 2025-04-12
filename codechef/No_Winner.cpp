#include<bits/stdc++.h>
using namespace std;

#define ll         long long
#define ff         first
#define ss         second
#define pb         push_back
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()

void solve(){
    int a,b,c,m;
    cin >> a >> b >> c >> m;
    int ab = abs(a-b);
    int bc = abs(b-c);
    int ca = abs(c-a);
    if((ab <= m) or (bc <= m) or (ca <= m)) cout << "YES" << nl;
    else cout << "NO" << nl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}