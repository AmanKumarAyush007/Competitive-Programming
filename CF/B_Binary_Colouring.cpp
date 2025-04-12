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
    cout << 32 << nl;
    vector<int> v;

    for(int i = 0; i < 32; i++){
        if(n&(1LL<<i)) v.pb(1);
        else v.pb(0);
    }

    for(int i = 0; i < 31; i++){
        bool first = true;
        int indF= i;
        int indL= i+1;
        

        while(v[i] == 1 && v[i] == v[i+1]){
            // cout << indF << " " << indL << nl;
            first = false;
            indL++; 
            i++;
        }

        if(first == false){
            for(int j = indF; j <= indL; j++){
                v[j] = 0;
            }
            v[indF] = -1;
            v[indL] = 1;
            i--;
        }

    }
    for(auto &i : v)cout << i << " ";
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