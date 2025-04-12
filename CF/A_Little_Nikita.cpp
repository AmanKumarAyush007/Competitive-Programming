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
    cin>>n>>m;
    if(n==m) cout<<"Yes"<<endl;
    else if(n<m) cout<<"No"<<endl;
    else{
        if((n-m) % 2 == 0) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
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