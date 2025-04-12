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
    int ans = 1;
    int cnt = 1;
    for(int i = 0; i < n-1; i++){
        if(a[i+1] >= a[i]) cnt++;
        else cnt = 1;
        ans = max(cnt,ans);
    }
    cout << ans << nl;
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