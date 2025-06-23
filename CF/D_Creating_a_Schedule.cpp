#include<bits/stdc++.h>
using namespace std;

#define int        int64_t
#define ff         first
#define ss         second
#define pb         push_back
#define inf        LLONG_MAX
#define hell       LLONG_MIN
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()
#define sm(v)      accumulate(all(v),0LL)
#define inp(v)     for(auto& x : v) cin >> x;
#define setbit(x)  __builtin_popcountll(x)


void solve(){
    int n,k;
    cin >> n >> k;
    int a[k];
    inp(a)

    sort(a,a+k);


    int mat[n][6];

    for(int j = 0; j < 6; j++){
        if(j % 2 == 0){
            for(int i = 0; i < n; i++){
                mat[i][j] = a[i]; 
            }
        }
        else{
            for(int i = 0; i < n; i++){
                mat[i][j] = a[k-1-i]; 
            }
        }
        
    }


    vector<int> p,q;
    int curr = 0;

    for(int i = 0; i < n; i++){
        if(p.size() >= k) break;
        if(i % 2 == 0){
            p.pb(mat[curr][0]);
            q.pb(mat[curr][1]);
        }
        else {
            p.pb(q[q.size()-1]);
            q.pb(p[p.size()-2]);
            curr++;
        }
    }


    for(int j = 0; j < 6; j++){
        if(j%2 == 0){
            for(int i = 0; i < n; i++){
                mat[i][j] = p[i];
            }
        }
        else{
            for(int i = 0; i < n; i++){
                mat[i][j] = q[i];
            }
        }
    }

    

    for(auto &el : mat){
        for(auto &i : el) cout << i << " ";
        cout << nl;
    }

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