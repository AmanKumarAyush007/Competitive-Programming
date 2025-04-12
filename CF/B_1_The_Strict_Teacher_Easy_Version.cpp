#include<bits/stdc++.h>
using namespace std;

#define int        long long
#define ff         first
#define ss         second
#define pb         push_back
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()

void solve(){
    int n,m,q;
    cin >> n >> m >> q;
    int t1,t2;
    cin >> t1 >> t2;
    int d;
    cin >> d;

    if(d<=max(t1,t2) && d>=min(t1,t2)) cout << abs(t1-t2)/2;
    else if(d >= max(t1,t2)) cout << n - max(t1,t2);
    else cout << min(t1,t2) - 1;

    // cout << min(abs(t1-d),abs(t2-d));
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