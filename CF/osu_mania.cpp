#include<bits/stdc++.h>
using namespace std;

#define ll         long long
#define ff         first
#define ss         second
#define pb         push_back
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()

void solve(){
    int n;
    cin >> n;
    vector<int> v;
    char a[n][4];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 4; j++){
            cin >> a[i][j];
        }
    }
    for(int i = n-1; i >= 0; i--){
        for(int j = 0; j < 4; j++){
            if(a[i][j] == '#') v.pb(j+1);
        }
    }

    for(auto &i : v) cout << i << " ";
    cout << nl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}