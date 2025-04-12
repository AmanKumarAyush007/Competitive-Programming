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
    for(int i = 1; i < s.size(); i++){
        int curr = i;
        int j = i-1;
        while(j >= 0 && s[i] - s[j] > 1){
            s[i]--;
            swap(s[i],s[j]);
            j--,i--;
        }
        i = curr;
    }
    cout << s << nl;
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