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
    cin>>s;
    int c1 = 0,c2 = 0;
    for(int i = 0; i < 2; i++){
        if(s[i]=='1') c1++;
    }
    for(int i = 2; i < 4; i++){
        if(s[i]=='1') c2++;
    }
    if(c1+c2 == 4) cout<<441<<nl;
    else if(c1+c2 == 3) cout<<231<<nl;
    else if(c1+c2 == 1) cout<<11<<nl;
    else if (c1+c2 == 0) cout<<1<<nl;
    else{
        if(c1 == 2 or c2 == 2) cout<<21<<nl;
        else cout<<121<<nl;
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