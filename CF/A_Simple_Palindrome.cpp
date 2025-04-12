#include<bits/stdc++.h>
using namespace std;

#define int        long long
#define ff         first
#define ss         second
#define pb         push_back
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()

void solve(){
    string c[5] = {"a","e","i","o","u"};
    int n;
    cin >> n;
    string s;

    for (int i = 0; i < 5; ++i) 
    {
        for (int j = 0; j < n / 5 + (i < n % 5); ++j) s += c[i];
    } 

    cout << s;
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