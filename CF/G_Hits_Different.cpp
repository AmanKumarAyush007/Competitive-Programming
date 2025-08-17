#include<bits/stdc++.h>
using namespace std;

#define int              int64_t
#define ff               first
#define ss               second
#define pb               push_back
#define inf              LLONG_MAX
#define hell             LLONG_MIN
#define nl               '\n'
#define all(a)           (a).begin(),(a).end()
#define rall(a)          (a).rbegin(),(a).rend()
#define sm(v)            accumulate(all(v),0LL)
#define inp(v)           for(auto& x : v) cin >> x;
#define setbit(x)        __builtin_popcountll(x)
#define lg(x)            (63 - __builtin_clzll(x)) //log base 2
#define prefixsum(a)     partial_sum(all(a), (a).begin());
#define suffixsum(a)     partial_sum(rall(a), (a).rbegin());


#ifndef ONLINE_JUDGE
#include "debug.h" 
#else
  #define debug(x...)
#endif

vector<vector<int>> v(1500, vector<int>(1500));
map<int,pair<int,int>> indx;

void preprocess(){

    for(int i = 0; i < 1500; i++){
        for(int j = 0; j < 1500; j++){
            indx[v[i][j]] = {i,j};
            v[i][j] = v[i][j] * v[i][j];
        }
    }

    for(auto &row : v){
        prefixsum(row);
    }

    for(int j = 0; j < 1500; j++){
        for(int i = 1; i < 1500; i++){
            v[i][j] += v[i-1][j];
        }
    }
}

void init(){

    int f = 1;
    v[0][0] = 1;
    for(int i = 1; i < 1500; i++){
        v[i][0] = f + v[i-1][0];
        f++;
    }
    f = 2;
    for(auto &row : v){
        int curr = f;
        for(int i = 1; i < row.size(); i++){
            row[i] = row[i-1] + curr;
            curr++;
        }
        f++;
    }
    
    preprocess();

}


void solve(){
    int n;
    cin >> n;

    auto [i,j] = indx[n]; 

    cout << v[i][j];
    cout << nl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    init();

    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}