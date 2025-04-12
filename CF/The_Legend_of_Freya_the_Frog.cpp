#include<bits/stdc++.h>
using namespace std;

#define ll         long long
#define ff         first
#define ss         second
#define pb         push_back
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()

void solve(){
    int x,y,k;
    cin >> x >> y >> k;
    int X = x/k + (x%k != 0);
    int Y = y/k + (y%k != 0);
    if(X == Y) cout << X+Y;
    else if(X < Y) cout << 2*Y;
    else  cout << 2*Y + 2*(X-Y) - 1;
    cout << nl;
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