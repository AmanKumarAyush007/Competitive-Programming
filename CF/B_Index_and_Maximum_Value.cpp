#include<bits/stdc++.h>
using namespace std;

#define ll         long long
#define ff         first
#define ss         second
#define pb         push_back
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()

void solve(){
    int n,m;
    cin >> n >> m;
    vector<int> v(n);
    for(auto &i : v) cin >> i;
    int mx = *max_element(all(v));
    vector<int> sol;
    for(int i = 0; i < m; i++){
        char c; cin >> c;
        int l,r;
        cin >> l >> r;
        if(mx>=l && mx<=r) {
            if(c == '+')  mx++ ;
            else mx--;
        }
        sol.pb(mx);
    }
    for(auto &i : sol) cout << i << " ";
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