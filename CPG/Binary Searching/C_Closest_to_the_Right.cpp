#include <bits/stdc++.h>
using namespace std;

int binarySearch(int *a,int tar,int n){
    int h = n;
    int l = -1;
    int mid = (h+l)/2;
    int ans = n;
    while(h>l+1){
        mid = (h+l)/2;
        if(a[mid] >= tar){
            h=mid;
            ans = mid;
        } 
        else l = mid;
    }
    // if(h == n-1 && a[h] < tar) return h+1;
    return ans+1; 
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x;
    cin >> n >> x;

    int a[n];
    int b[x];

    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    for(int i = 0; i < x; i++){
        cin>>b[i];
        int ans = binarySearch(a,b[i],n);
        cout<<ans<<endl;
    }

    return 0;
}