#include<bits/stdc++.h>
using namespace std;

#define ll         long long
#define ff         first
#define ss         second
#define pb         push_back
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()

void solve(){
    int n,m,a,b;
    cin >> n >> m >> a >> b;
    float na = a;
    float mb = b/m;
    if (n >= m)
    {
        if (a <= mb)
            cout << a * n << nl;
        else
        {
            cout << (n / m) * b + min(min((min((n % m) * a, (n % m) * b)),b),a*n) << nl;
        }
    }

    else cout << min(b,a*n) << nl;
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