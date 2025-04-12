#include<bits/stdc++.h>
using namespace std;

#define ll         long long
#define ff         first
#define ss         second
#define pb         push_back
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()

void solve(){
    int n ;
    cin >> n;
    string s;
    cin >> s;
    int count = 0;
    for(int i = 0; i < n-1; i++){
        if(s[i] == s[i+1]) count++;  
    }
    cout << count << nl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}