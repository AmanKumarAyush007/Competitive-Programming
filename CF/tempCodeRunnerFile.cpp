#include <bits/stdc++.h>
using namespace std;

#define int int64_t
vector<int>pt;

void ptr(){
    pt.push_back(1);
    for(int i=0;i<30;i++){
        pt.push_back(pt.back()*3);
    }
}
void solve() {
   int n;
   cin>>n;
   int p=0;
   while(pt[p]<=n){
    p++;
   }
   p--;
  // cout<<p<<endl;
   int ans=0;
   if(pt[p+1]==n){
    ans+=((pt[p+2]+((p+1)*pt[p])));
    n-=(pt[p+1]);
   }
   else if(pt[p]*2<=n){
    ans+=(2*((pt[p+1]+((p)*pt[p-1]))));
    n-=(pt[p]*2);
  //  cout<<ans<<endl;
   }
   else{
   ans+=((pt[p+1]+((p)*pt[p-1])));
    n-=pt[p];
   }
   ans+=n*3;
   cout<<ans<<endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    ptr();
    cin >> t;
    while (t--) solve();
    return 0;
}