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
    const int k = 998244353;

    int n = s.size();

    vector<int> v;

    int cnt = 1;
    

    for(int i = 0; i < n; i++){
        while(s[i] == s[i+1]){
            cnt++;
            i++;
        }
        v.pb(cnt);
        cnt = 1;
    }

    int more = 0;
    int arr = 1;

    for(auto &i : v){
        if(i > 1){
            more += i-1;
            arr = (arr*i)%k;
        }
    }

    for(int i = 1; i <= more; i++){
        arr = (arr*i) % k;
    }

    cout << more << " " << arr; 

    // for(auto &i : v) cout << i << " ";
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