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
    int n = s.size();
    vector<int> v(n,0);
    for(int i = 0; i < n; i++){
        if(s[i] >= '0' && s[i] <= '9'){
            int k = s[i] - '0';
            for(int j = i; j <= min(i+k,n-1) ; j++){
                v[j]++;
            }
            for(int j = i-1; j >= max(i-k,0LL) ; j--){
                v[j]++;
            }
        }
    }

    for(auto &i : v){
        if(i > 1) {
            cout << "unsafe" << nl;
            return;
        } 
    }

    cout<< "safe" << nl;
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