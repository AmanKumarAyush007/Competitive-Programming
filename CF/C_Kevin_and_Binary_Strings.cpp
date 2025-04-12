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
    int i = 0;
    while(i < n){
        if(s[i] == '0') break;
        i++;
    }
    if(i == n) cout << n << " " << n << " " << 1 << " " << n;
    else {
        string mn = s.substr(i);
        string comp = mn;
        int k = mn.size();
        int ans = -1;
        for(int j = 0; j < i ; j++){
            string t = s.substr(j,k);
            string x = "";
            for(int l = 0; l < k; l++){
                int te = t[l] - '0';
                int mne = mn[l] - '0';
                int Xo = te^mne;
                char c= '0' + Xo;
                x += c;
            }
            if(x > comp) {
                comp = x;
                ans = j;
            }
        }
        ans++;
        cout << 1 << " " << n << " " << ans << " " << ans + k - 1;
    }

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