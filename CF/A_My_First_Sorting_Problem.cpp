#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define pb push_ back
#define endl '\n'

void solve(){
    int a[2];
    for(int i = 0;i<2;i++){
        cin>>a[i];
    }
    sort(a,a+2);
    for(int i = 0;i<2;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
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