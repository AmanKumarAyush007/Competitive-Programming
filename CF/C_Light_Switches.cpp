#include<bits/stdc++.h>
using namespace std;

#define int        long long
#define ff         first
#define ss         second
#define pb         push_back
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()

void solve(){
    int n,k;
    cin >> n >> k;
    int  a[n];
    for(auto &i : a) cin >> i;

    sort(a,a+n);

    int lo = a[n-1];
    int hi = lo + k -1;

    for(int i = 0; i < n-1; i++){
        int diff = lo - a[i];
        int curL = a[i] + 2*k*(diff/(2*k));
        if(diff % (2*k) >= k) curL += (2*k);  //edge case
        int curH = curL+k-1;
        lo = max(curL,lo);
        hi = min(curH,hi);
        if(lo>hi){
            cout << -1 << nl;
            return ;
        }
    }
    
    cout << lo;

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