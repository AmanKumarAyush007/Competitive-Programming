#include<bits/stdc++.h>
using namespace std;

#define int        int64_t
#define ff         first
#define ss         second
#define pb         push_back
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()
#define inp(v)     for(auto& x : v) cin >> x


void addFactor(int n, map<int, int>& mp) {
    int i = 2;
    while(i*i <= n){
        while(n%i == 0) {
            mp[i]++;
            n /= i;
        }
        i++;
    }

    if(n > 1) mp[n]++;
}

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    inp(v);
    
    map<int, int> mp;

    for(int x : v) {
        addFactor(x, mp);
    }
    
    for(auto [a, b] : mp) {
        if(b % n != 0) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}