#include<bits/stdc++.h>
using namespace std;

#define int        long long
#define ff         first
#define ss         second
#define pb         push_back
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()

int lg(int base, int x){
    double a = log2(base);
    double b = log2(x);

    if(base == 1) return 1;

    return b/a;

}

void solve(){
    int n;
    cin >> n;
    int k;
    cin >> k;

    int ans = 0;

    if(n < k){
        ans = n;
        n = 0;
    }
    if(k == 1){
        ans = n;
        n = 0;
    }

    while(n > 0){
        if(lg(k,n) == 0){
            ans += n;
            break;
        }
        n -= pow(k,lg(k,n));
        ans++;
    }

    cout << ans;

    cout << nl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}