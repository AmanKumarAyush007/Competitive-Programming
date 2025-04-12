#include<bits/stdc++.h>
using namespace std;

#define ll         long long
#define ff         first
#define ss         second
#define pb         push_back
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()

void solve(){
    int a,b,c;
    cin >> a >> b >> c;
    int ar[3];
    ar[0] = a;
    ar[1] = b;
    ar[2] = c;
    int k = 5;
    while(k--){
        sort(ar,ar+3);
        ar[0]++;
    }
    int ans = 1;
    for(auto &i : ar) ans *= i;
    cout << ans << nl;
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