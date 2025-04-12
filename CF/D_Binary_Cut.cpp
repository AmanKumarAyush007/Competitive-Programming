#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define pb push_back
#define endl '\n'


void solve(){
    string s;
    cin>>s;
    int n = s.size();
    int count = 1;
    int k = 0;
    
    for(int i = 1; i<n; i++){
      if(s[i]==s[i-1]){ continue;}
      else count++;
      if(s[i-1]=='0' && s[i]=='1') {k = 1;}
    }
    cout<<count-k<<endl;
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