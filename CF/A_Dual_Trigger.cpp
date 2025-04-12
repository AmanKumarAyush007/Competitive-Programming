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
    cin>>n;
    string s;
    cin>>s;
    int ct1=0,ct0=0,ct11 = 0; 
    for(int i = 0; i < n; i++){
        if(s[i]=='1') ct1++;
        if(s[i]=='0') ct0++;
    }
    for(int i = 0; i < n; i++){
        if(s[i]=='1' && s[i+1]=='1') {
            ct11++;
            i++;
        }
    }
    if(ct1%2 == 0) {
        if( (ct1 == 2) && (ct11==1))cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    else cout<<"NO"<<endl;
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