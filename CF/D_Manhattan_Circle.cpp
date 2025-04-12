#include<bits/stdc++.h>
using namespace std;

#define ll         long long
#define ff         first
#define ss         second
#define pb         push_back
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()

void solve(){
    int x,y;
    cin>>x>>y;
    char grid[x][y];
    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            cin>>grid[i][j];
        }
    }
    int mxi = 0;
    int mxj = 0;
    int mni = x;
    int mnj = y;
    vector<pair<int,int>> point;
    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            if(grid[i][j]=='#'){
                point.pb(make_pair(i,j));
            }
        }
    }
    for(auto &pr : point){
        mxi = max(mxi,pr.ff);
        mxj = max(mxj,pr.ss);
        mni = min(mni,pr.ff);
        mnj = min(mnj,pr.ss);
    }
    mxi++;
    mxj++;
    mni++;
    mnj++;
    int ansi = (mxi + mni)/2;
    int ansj = (mxj + mnj)/2;

    cout<<ansi<<" "<<ansj<<nl;
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