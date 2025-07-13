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
    int n;
    cin >> n;
    string s;
    cin >> s;
    int q;
    cin >> q;
    int p = count(all(s),'+');
    int ne = count(all(s),'-');
    for(int i = 0; i < q; i++){
        int x,y;
        cin >> x >> y;
        int diff = x - y;
        if(diff == 0){
            if(p == ne) cout << "YES\n";
            else cout << "NO\n";
            continue;
        }
        if((((ne - p)*y)%(x-y) ) != 0) {
            cout << "NO\n";
            continue;
        }

        if(((y*(ne-p))/(x-y)) >= (-1*ne) && (((y*(ne-p))/(x-y)) <= (p))) cout << "YES\n" ;
        else cout << "NO\n";
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}