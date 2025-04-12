#include<bits/stdc++.h>
using namespace std;

#define ll         long long
#define ff         first
#define ss         second
#define pb         push_back
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()

void solve(){
    int x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    if(x1<=y1 and x2>=y2) cout<<"NO"<<nl;
    else if(x1>=y1 and x2<=y2) cout<<"NO"<<nl;
    else cout<<"YES"<<nl;
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