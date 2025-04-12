#include<bits/stdc++.h>
using namespace std;

#define ll         long long
#define ff         first
#define ss         second
#define pb         push_back
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()

void solve(){
    int x,y;
    cin>>x>>y;
    
    for(int  i = 0; i <= 30; i++){
        if(((1<<i) & x) != ((1<<i) & y)){
            cout<<(1<<i)<<nl;
            break;
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