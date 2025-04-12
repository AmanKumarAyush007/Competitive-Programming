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
    int a[n];

    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    sort(a,a+n);
    int sum = (a[n-1]-a[0]) + (a[n-1]-a[1] + (a[n-2]-a[0] + (a[n-2]-a[1])));
    cout<<sum<<endl;

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