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
    cin >> n;
    int a[n];
    for(auto &i : a) cin >> i;


    vector<pair<int,int>> vp;
    for(int i = 0; i < n; i++){
        pair<int,int> p;
        p = {a[i],(i+1)};
        vp.pb(p);
    }

    sort(all(vp));


    vector<pair<pair<int,int>,pair<int,int>>> vpp;

    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; ){
            if((vp[i].ff * vp[j].ff) <= 2*n){
                pair<pair<int,int>,pair<int,int>> pp;
                pp = {vp[i],vp[j]};
                vpp.pb(pp);
                j++;
            }
            else break;
        }
        if((vp[i+1].ff * vp[i].ff) > 2*n) break;
    }

    int count = 0;

    for(auto &[a,b] : vpp){
        if((a.ff * b.ff) == (a.ss + b.ss)) count++;
    }

    cout << count << nl;

    // for(auto &[a,b] : vpp) cout <<"->"<< a.ff << " " << a.ss << " "  << b.ff << " " << b.ss <<"<-"<< nl;
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