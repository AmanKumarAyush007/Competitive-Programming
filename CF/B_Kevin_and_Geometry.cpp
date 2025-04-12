#include<bits/stdc++.h>
using namespace std;

#define int        int64_t
#define ff         first
#define ss         second
#define pb         push_back
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()
#define inp(v)     for(auto& x : v) cin >> x


void solve(){
    int n;
    cin >> n;
    vector<int> ar(n);
    inp(ar);
    map<int,int> mp;
    for(auto &i : ar){
        mp[i]++;
    }
    bool check = false;
    int cnt = 0;
    vector<int> v;
    for(auto &[a,b] : mp){
        if(b >= 2) {
            cnt++;
            v.pb(a);
        }
        if(b >= 4){
            for(int i = 0; i < 4; i++){
                cout << a << " ";
            }
            cout << nl;
            return;
        }
    }
    if(cnt == 0){
        cout << -1 << nl;
    }
    else if(cnt>=2){
        for(int i = 0; i < 2; i++){
            cout << v[i] << " " << v[i] << " ";
        }
        cout << nl;
    }
    else {
        int c = v[0];
        sort(all(ar));
        auto it = upper_bound(all(ar),c);
        it = it-1;
        int ind = it - ar.begin();
        if(ind >= 3){
            for(int i = ind; i >= ind-3; i--){
                cout << ar[i] << " ";
            }
        }
        else{
            int a = -1,b=-1;
            vector<int> ne;
            int ct = 0;
            for(auto &i : ar) {
                if(i != c || ct > 1) ne.pb(i);
                else ct++;
            }    

            for(int i = 0; i < ne.size()-1; i++){
                if(((2*c) + ne[i] + ne[i+1]) > 2*(max(ne[i],ne[i+1]))) {
                    a = ne[i];
                    b = ne[i+1];
                    break;
                }
            }

            if(a == -1) cout << -1 << nl;
            else{
                cout << c << " " << c << " " << a << " " << b << nl;
            }
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