#include<bits/stdc++.h>
using namespace std;

#define int        long long
#define ff         first
#define ss         second
#define pb         push_back
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
 
    string s;
    cin >> s;
 
    int cntW = 0;
    int st = 0;
 
    for (int i = 0; i < n; i++) {
        int end = i+1;
        if (s[i] == 'L') {
            st = i + 1;
            continue;
        }
        if (end - st < m) {
            continue;
        }
        if (s[i] == 'C') {
            cout << "NO" << nl;
            return;
        }
        if (s[i] == 'W') {
            cntW++;
            if (cntW > k) {
                cout << "NO" << nl;
                return;
            }
        }
    }
    cout << "YES";
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