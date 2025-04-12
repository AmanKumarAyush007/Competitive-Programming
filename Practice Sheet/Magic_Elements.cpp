#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define pb push_ back

void solve(){
    int n,k;
    cin>>n>>k;
    int a[n]; 
    int sum = 0;
    for(int i = 0; i < n; i++){
        cin>>a[i];
        sum+=a[i];
    }
    int count=0;
    for(int i = 0; i < n; i++){
        if(a[i]+k>sum-a[i]) count++;
    }
    cout<<count<<endl;
}

int main(){
  ll t;
  cin >> t;
  while(t--){
    solve();
  }
  return 0;
}