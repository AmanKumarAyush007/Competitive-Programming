#include<bits/stdc++.h>
using namespace std;

#define int        long long
#define ff         first
#define ss         second
#define pb         push_back
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()

void solve(){
    int n;
    cin >> n;
    int k;
    cin >> k;

    int a[n];
    for(auto &i : a) cin >> i;

    vector<int> v(n+5 , 0);

    while(k--){
        int x,y;
        cin >> x >> y;

        v[x]++;
        v[y+1]--;
    }

    for(int i = 1; i < v.size(); i++){
        v[i] += v[i-1];
    }

    sort(all(v),greater<int>());
    sort(a,a+n,greater<int>());

    int ans = 0;

    for(int i = 0; i < n; i++){
        ans += v[i]*a[i];
    }

    cout <<ans<< nl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}