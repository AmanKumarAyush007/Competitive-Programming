#include<bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define debug(x...)
#endif
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

void solve(){
    int n,k;
    cin>>n>>k;

    vector<vector<int>> a(n);
    for(int i=0;i<n;i++) a[i].assign(i+1,-1);

    int pt=0;

    auto nb=[&](int r,int c){
        vector<pair<int,int>> v;
        if(r>c) v.push_back({r-1,c});
        if(r+1<n) v.push_back({r+1,c});
        if(c>0) v.push_back({r,c-1});
        if(c<r) v.push_back({r,c+1});
        return v;
    };

    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            if(a[i][j]==-1){
                int cp=pt++;
                queue<pair<int,int>> q;
                q.push({i,j});
                a[i][j]=cp;
                int sz=1;

                while(!q.empty() && sz<k){
                    auto [r,c]=q.front(); q.pop();
                    for(auto [nr,nc]:nb(r,c)){
                        if(a[nr][nc]==-1 && sz<k){
                            a[nr][nc]=cp;
                            q.push({nr,nc});
                            sz++;
                        }
                    }
                }
            }
        }
    }

    vector<char> col(pt,' ');

    for(int p=0;p<pt;p++){
        set<char> adj;
        for(int i=0;i<n;i++){
            for(int j=0;j<=i;j++){
                if(a[i][j]==p){
                    for(auto [nr,nc]:nb(i,j)){
                        int q=a[nr][nc];
                        if(q!=p && col[q]!=' ') adj.insert(col[q]);
                    }
                }
            }
        }
        for(char c='a';c<='z';c++){
            if(!adj.count(c)){
                col[p]=c;
                break;
            }
        }
    }

    cout<<pt<<nl;
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++) cout<<col[a[i][j]];
        cout<<nl;
    }
}

signed main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("C:/Users/desktop/Downloads/patchwork_pyramid_validation_input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}
