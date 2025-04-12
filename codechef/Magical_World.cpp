#include<bits/stdc++.h>
using namespace std;

#define ll         long long
#define ff         first
#define ss         second
#define pb         push_back
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()

void solve(){
    int a, b, x;
    cin >> a >> b >> x;
    if ((a * b) <= (x * x))
        cout << 0 << endl;
    else
    {
        int ans = 0;
        if(a<=(x * x) || b <= (x * x)) ans = 1;
        else ans = 2;
        cout << ans << endl;
    }
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