#include<bits/stdc++.h>
using namespace std;

#define ll         long long
#define ff         first
#define ss         push_back
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()

void solve(){
    string a,b;
    cin>>a>>b;
    char temp = b[0];
    b[0] = a[0];
    a[0] = temp;
    cout<<a<<" "<<b<<nl;
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