#include<bits/stdc++.h>
using namespace std;

#define ll         long long
#define ff         first
#define ss         second
#define pb         push_back
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()

int f(int a,int b){
    if(a>b) return 1;
    if(a==b) return 0;
    return -1;
}

void solve(){
    int a1,a2,b1,b2;
    cin >> a1 >> a2 >> b1 >> b2;
    int ans = 0;
    if( (f(a1,b1)+f(a2,b2)) > 0) ans++;
    if( (f(a1,b2)+f(a2,b1)) > 0) ans++;
    
    cout << ans*2 <<nl;
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