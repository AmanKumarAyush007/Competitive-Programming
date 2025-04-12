#include<bits/stdc++.h>
using namespace std;

#define ll         long long
#define ff         first
#define ss         second
#define pb         push_back
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()


int solve(){
    int l,r;
    cin>>l>>r;
    int ans = log2(r);
    return ans;
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        int ans = solve();
        cout<<ans<<nl;
    }
    return 0;
}