#include<bits/stdc++.h>
using namespace std;

#define int        int64_t
#define ff         first
#define ss         second
#define pb         push_back
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()

void solve(){
    string s;
    cin >> s;
    int n = s.size();
    string ans;
    for(int i = n-1; i >= 0; i--){
        if(s[i] == 'p') ans += 'q';
        else if (s[i] == 'q') ans += 'p';
        else ans += 'w';
    }
    cout << ans << nl;
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