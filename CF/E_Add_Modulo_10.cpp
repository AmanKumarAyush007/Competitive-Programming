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
    int a[n];
    inp(a)
    
    set<int> st;
    vector<int> v;
    for(int i = 0; i < n; i++){
        if(a[i]%10 == 5) a[i] += 5;
        else if(a[i]%10 != 0){
            while(a[i]%10 != 2) a[i] += a[i]%10;
        }
        if(a[i] % 10 == 0) st.insert(a[i]);
        else v.pb(a[i]);
    }

    sort(all(v));

    if(st.size() > 1) cout << "No\n";
    else if(st.size() == 1) {
        if( v.size() == 0) cout << "Yes\n";
        else cout <<"No\n";
    }    
    else{
        if(v.size() == 1) cout << "Yes\n";
        else{
            for(int i = 0; i < v.size()-1; i++){
                if((v[i+1] - v[i]) % 20 != 0) {
                    cout << "No\n";
                    return;
                }
            }
            cout << "Yes\n";
        }
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