#include<bits/stdc++.h>
using namespace std;

#define int        long long
#define ff         first
#define ss         second
#define pb         push_back
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()

void solve(){
    int n,m,k;
    cin >> n >> m >> k;
    set<int> a,b;
    for(int i = 0; i < n; i++){
        int ele;
        cin >> ele;
        if(ele<=k) a.insert(ele);
    }
    for(int i = 0; i < m; i++){
        int ele;
        cin >> ele;
        if(ele<=k) b.insert(ele);
    }


    vector<int> v1(k+1,0);
    vector<int> v2(k+1,0);

    for(auto &i : a) {
        v1[i]++;
    }

    for(auto &i : b) {
        v2[i]++;
    }

    // for(auto &i : v2) cout << i << " ";

    int uni1 = 0, uni2 = 0, com = 0;

    for(int i = 1; i <= k; i++){
        if(v1[i] == 1 && v2[i] == 0) uni1++;
        else if(v1[i] == 0 && v2[i] == 1) uni2++;
        else if(v1[i] == 1 && v2[i] == 1) com++;
        else {
            cout << "NO" <<nl;
            return;
        }
    }

    int tk1 = min(uni1,k/2);
    int tk2 = min(uni2,k/2);

    if(tk1+tk2 == k) cout << "YES" << nl;
    else {
        if(tk1 != k/2 && com < ((k/2) - tk1)) {
            cout << "NO" << nl;
            return;
        }
        else if(tk1 != k/2){
            tk1 = k/2;
            com -= ((k/2) - tk1);
        }
        if(tk2 != k/2 && com < ((k/2) - tk2)) {
            cout << "NO" << nl;
            return;
        }
        else if(tk2 != k/2){
            tk2 = k/2;
            com -= ((k/2) - tk1);
        }
        cout << "YES" << nl;

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