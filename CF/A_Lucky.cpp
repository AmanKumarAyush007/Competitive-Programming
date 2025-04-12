#include<bits/stdc++.h>
using namespace std;

#define ll         long long
#define ff         first
#define ss         second
#define pb         push_back
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()

void solve(){
    string s;
    cin >> s;
    int sum = 0,sum1 = 0;
    for(int i = 0; i < 3; i++){
        sum += s[i]-'0';
    }
    for(int i = 3; i < 6; i++){
        sum1 += s[i]-'0';
    }

   if(sum1 != sum) cout << "NO" << nl;
   else cout << "YES" << nl;
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