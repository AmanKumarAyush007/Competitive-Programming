#include<bits/stdc++.h>
using namespace std;

#define ll         long long
#define ff         first
#define ss         second
#define pb         push_back
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()

void solve(){

    int n,l,p,d,k,c,nk,np,ans;
    cin>>n>>k>>l>>c>>d>>p>>nk>>np;
    k=k*l/nk;
    c=c*d;
    p=p/np;
 
    cout<<min(min(k,c),p)/n;
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