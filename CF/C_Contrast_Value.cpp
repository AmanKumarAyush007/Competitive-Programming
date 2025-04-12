#include<bits/stdc++.h>
using namespace std;

#define int        int64_t
#define ff         first
#define ss         second
#define pb         push_back
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()

void solve(){
    int n;
    cin >> n;
    int a[n];
    for(auto &i : a) cin >> i;
    
    int diff[n-1];
    for(int i = 0; i < n-1; i++){
        diff[i] = a[i+1] - a[i];
    }

    bool all = true;
    bool sig = true;

    for(auto &i : diff) if(i != 0) all = false;   // to check all are same or not;
    
    vector<int> num;
    for(auto &i : diff){
         if(i > 0) num.pb(1);
         else if (i < 0) num.pb(-1);
    }

    int cng = 0;

    if(num.size() >= 2){
        for(int i = 0; i < num.size()-1; i++){
            if(num[i] != num[i+1]) cng++;    
        }
    }

    if(all) cout << 1;
    else  cout << 2 + cng;
    
    // for(auto &i : diff) cout << i << " ";
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