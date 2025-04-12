#include<bits/stdc++.h>
using namespace std;

#define int        int64_t
#define ff         first
#define ss         second
#define pb         push_back
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()

void solve(){
    int n,k;
    cin >> n >> k;
    vector<int> v(n);
    for(auto &i : v) cin >> i;

    vector<int> bit(32);

    vector<int> ind;

    for(int i = 0; i < 32; i++){
        bit[i] = k & (1LL << i);
        if(bit[i] != 0) ind.pb(i);
    }
    vector<int> sol;
    vector<int> temp;



    for(int i = 0; i < n; i++){
        bool ck = true;
        for(int j = 0; j < ind.size(); j++){
            if((v[i] & (1LL << ind[j])) == 0) ck = false;
        }
        if(ck) {
            sol.pb(i+1);
            temp.pb(v[i]);
        }
    }


    if(sol.size() == 0) cout << "NO" << nl;
    else{
        int chk = temp[0];
        for(int i = 1; i < temp.size(); i++){
            chk = chk & temp[i];
        }
        if(chk != k) cout << "NO" << nl;
        else{
            cout << "YES" << nl;
            cout << sol.size() << nl; 
            for(auto &i : sol) cout << i << " "; 
            
        }
    }

    // for(auto &i : ind) cout << i << " ";

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