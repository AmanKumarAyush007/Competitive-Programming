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
    int n = s.size();
    int sum = 0;
    map<char,int> mp;
    mp['2'] = 0, mp['3'] = 0;
    for(int i = 0; i < n; i++){
        sum += s[i] - '0';
        if(s[i] == '2' || s[i] == '3') mp[s[i]]++;
    }
    int x = mp['2'], y = mp['3'];
    for(int i = 0; i <= x; i++){
        for(int j = 0; j <= y; j++){
            if(((sum + (2*i)) + (6*j)) % 9 == 0) {
                cout << "YES" << nl;
                return;
            }
        }
    }
    cout << "NO" << nl;
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