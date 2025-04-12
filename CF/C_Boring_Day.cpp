#include<bits/stdc++.h>
using namespace std;

#define int        long long
#define ff         first
#define ss         second
#define pb         push_back
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()

void solve(){
    int n,ql,qr; 
    cin >> n >> ql >> qr;

    int a[n];
    for(auto &i : a) cin >> i;


    int curr = 0;
    int l = 0,r = 0;
    int ans = 0;

    while(l < n){
        while(r < n && curr < ql){
            curr += a[r];
            r++;
        }
        if(curr >= ql && curr <= qr) {
            ans++;
            l = r;
            curr = 0;
        }
        else {
            curr -= a[l];
            l++;
        }
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