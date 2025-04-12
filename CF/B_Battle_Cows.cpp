#include<bits/stdc++.h>
using namespace std;

#define ll         long long
#define ff         first
#define ss         second
#define pb         push_back
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()

bool check(int mx, int a){
    return mx>a;
}

int binarySearch(int *ma,int tar, int low,int high){ //to find the minimum index which is stricly greater than target
    int ans = -1;
    int l = low;
    int h = high;
    while(h>=l){
        int mid = l + (h - l) / 2;
        if(check(ma[mid],tar)){
            ans = mid;
            h = mid - 1;
        }
        else {
            mid = l+1;
        }
    }
    return ans;
}

void solve(){
    int n, k ;
    cin >> n >> k;
    k-=1;
    int a[n];
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    int ma[n];
    int mx = a[0];
    for(int i = 0; i < n; i++){
        mx = max(a[i],mx);
        ma[i] = mx;
    }
    if(a[k] == ma[k]){
        int prev = k;
        int next = binarySearch(ma,a[k],k+1,n-1);
        cout<<next;
    }
    // cout<<k<<nl;
    // for(int i = 0; i < n; i++){
    //     cout<<ma[i]<<" ";
    // }
    // cout<<endl;
    // for(int i = 0; i < n; i++){
    //     cout<<a[i]<<" ";
    // }

    
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