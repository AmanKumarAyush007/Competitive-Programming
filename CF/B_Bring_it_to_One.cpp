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
    int a[n];

    int cnt = 0;
    int cnt0 = 0;

    for(auto &i : a) {
        cin >> i;
        if(i < 0) cnt++;
        if(i == 0) cnt0++;
    }

    int sum = 0;


    for(int i = 0; i < n; i++){
        sum += abs(1 - a[i]);
    }

    int ans = 0;

    if(cnt % 2 == 0) ans = sum - (cnt*2);
    else {
        if(cnt0) ans = sum - (cnt*2);
        else ans = sum - (cnt/2)*4 ;
    }

    cout <<ans;


    
    cout << nl;
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