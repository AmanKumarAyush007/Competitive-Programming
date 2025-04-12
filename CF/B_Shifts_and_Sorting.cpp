#include<bits/stdc++.h>
using namespace std;

#define int        long long
#define ff         first
#define ss         second
#define pb         push_back
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()

void solve(){
    string s;
    cin >> s;

    int cnt = 0;
    int ans = 0;

    for(int i = 0; i < s.size(); i++){
        if(s[i] == '1') cnt++;
        else if(cnt)  ans += cnt+1;
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