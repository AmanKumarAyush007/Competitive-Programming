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
    string s,t;
    cin >> s >> t;
    bool check = true;
    for(int i = 0; i < n; i++){
        if(s[i] == '1') break;
        if(s[i] == '0' and t[i] == '1'){
            check = false;
            break;
        }
    }
    if(check)  cout <<"YES" <<nl; 
    else cout << "NO" << nl;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}