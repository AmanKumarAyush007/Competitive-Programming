#include<bits/stdc++.h>
using namespace std;

#define int        int64_t
#define ff         first
#define ss         second
#define pb         push_back
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()
#define inp(v)     for(auto& x : v) cin >> x


void solve(){
    string s;
    cin >> s;
    vector<int> c(26,0);   

    for(auto &i : s) c[i - 'a']++;

    vector<int> odd;
    for(int i = 0; i < 26; i++){
        if(c[i] & 1) odd.pb(i);
    }

    string ans = "";
    if(odd.size() & 1) {
        int k = odd[odd.size()/2];
        ans += 'a' + k;
        c[k]--;
    }

    for(int i = 0; i < odd.size()/2; i++){
        c[odd[i]]++;
        c[odd[odd.size()-1 - i]]--;
    }

    for(int i = 25; i >= 0; i--){
        ans = string(c[i]/2,('a' + i)) + ans + string(c[i]/2,('a' + i)) ;
    }

    cout << ans << nl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}