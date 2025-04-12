#include<bits/stdc++.h>
using namespace std;

#define ll         long long
#define ff         first
#define ss         second
#define pb         push_back
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()

void solve(){
    int n,k;
    cin >> n >> k;
    string s,x;
    cin >> s >> x;
    int count0 = 0;
    int count1 = 0;
    for(auto &i : s) if(i == '0') count0++;
    for(auto &i : s) if(i == '1') count1++;
    int cn0 = count0;
    int cn1 = count1;
    // cout << count0 << count1;
    for(auto &i : x) if(i == '0') count0--;
    for(auto &i : x) if(i == '1') count1--;

    if(count0 != 0 or count1 != 0) cout << "NO" << nl; //if count doesn't equal
    else{
        int diff = 0;
        for(int i = 0; i < n; i++){
            if(x[i] != s[i]) diff++;
        }
        diff /= 2;
        if(k < diff) cout << "NO" << nl;
        else{
            if( (cn0 >= 2) or (cn1 >= 2) or (k-diff)%2 == 0) cout << "YES" << nl;
            else cout << "NO" << nl;
        }
    }
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