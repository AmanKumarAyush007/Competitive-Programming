#include<bits/stdc++.h>
using namespace std;

#define ll         long long
#define ff         first
#define ss         second
#define pb         push_back
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()

void solve(){
    int n;
    cin >> n;
    int a[n];
    for(auto &i : a) cin >> i;
    int l = 0, r = n-1;

    while (l<n and a[l] <= 0)
    {
        l++;
    }
    
    while (r>=0 and a[r] <= 0)
    {
        r--;
    }

    if(r <= l) cout << 0 << nl;
    else{
        int ans = 0;
        for(int i = l; i <= r; i++){
            if(a[i] < 0) ans++;
        }
        cout << ans << nl;
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