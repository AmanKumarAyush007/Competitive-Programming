#include<bits/stdc++.h>
using namespace std;

#define int        int64_t
#define ff         first
#define ss         second
#define pb         push_back
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()

int zero(int n){  //count the number of zeros in the last
    int cnt = 0;
    while(n > 0){
        if(n%10 == 0) {
            cnt++;
            n/=10;
        }
        else break;
    }
    return cnt;
}


int cntdig(int n){
    int cnt = 0;
    while(n > 0){
        cnt++;
        n/=10;
    }
    return cnt;
}



void solve(){
    int n,m;
    cin >> n >> m;
    int a[n];
    int dig = 0;
    for(auto &i : a) {
        cin >> i;
        dig += cntdig(i);
    }
    vector<pair<int,int>> z;

    for(auto &i : a){
        if(zero(i) != 0){
            z.pb({zero(i),i});
        }
    }

    sort(all(z),greater<pair<int,int>>());

    for(int i = 0; i < z.size(); i++){
        if(i%2 == 0) dig -= z[i].ff;
    }    

    if(dig >= m+1) cout << "Sasha\n";
    else cout << "Anna\n";

}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}