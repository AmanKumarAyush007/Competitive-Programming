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
    int arr[m+1];
    arr[0]=1;
    for(int i=0;i<m;i++){
        cin>>arr[i+1];
    }
    long long ans=0;
    for(int i=0;i<m;i++){
        if(arr[i]<arr[i+1]){
        ans += arr[i+1]-arr[i];
        }
        else if(arr[i]>arr[i+1]){ans += n - arr[i]+arr[i+1];}
    }
    cout<<ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}