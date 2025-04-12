#include<bits/stdc++.h>
using namespace std;

#define int        int64_t
#define ff         first
#define ss         second
#define pb         push_back
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()
#define inp(v)     for(auto& x : v) cin >> x
#define sm(v)      accumulate(all(v),0LL)

int A(int n){
    int k = 0;
    while(n--){
        k = k*10 + 9;
    }
    return k;
}

bool ck (int n){
    while(n){
        if(n % 10 == 7) return true;
        n /= 10;
    }
    return false;
}


void solve(){
    int n;
    cin >> n;
    // cout << A(n);
    if(ck(n)) {
        cout << 0 << nl;
        return;
    }

    for(int i = 1; i < 20; i++){
        int curr = n;
        curr += A(i);
        cout << curr << " ";
        if(ck(curr)) {
            cout << i << nl;
            return;
        }
    }

    cout << nl;
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