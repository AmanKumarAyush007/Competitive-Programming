#include<bits/stdc++.h>
using namespace std;

#define ll         long long
#define ff         first
#define ss         second
#define pb         push_back
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()

void solve(){
    int n,x;
    cin >> n >> x;
    int a[n];
    for(auto &i : a)cin >> i;
    int pre[n];
    for(int i = 0; i < n; i++){
        if(i == 0) pre[i] = a[i];
        else pre[i] = pre[i-1] + a[i];
    }
    int ans = 0;
    int mnsum = pre[x-1];

    for(int i = 1; i < n-x+1; i++){
        if(pre[i-1+x] - pre[i-1] < mnsum) {
            ans = i;
            mnsum = pre[i-1+x] - pre[i-1] ;
        }
    }

    cout << ans + 1 << nl;

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