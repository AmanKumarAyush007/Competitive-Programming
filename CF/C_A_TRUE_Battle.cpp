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
    string s;
    cin >> s;
    if(s[0] == '1' or s[n-1] == '1') cout << "YES" << nl;
    else{
        for(int i = 1; i < n-1; i++){
            if(s[i] == '1' && s[i] == s[i+1]){
                cout << "YES" << nl;
                return;
            }
        }
        cout << "NO" << nl;
    }
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