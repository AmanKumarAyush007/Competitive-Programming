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


int power(int base, int exp) {
    int res = 1;
    // base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) ;
        
        if(base < 1e7){
            base = (base * base);
        }
        else return -1;
        exp /= 2; 
    }
    return res;
}

void solve(){
    int x,y,n;
    cin >> x >> y >> n;
    set<int> st;
    for(int i = 0; i <= 100; i++){
        for(int j = 0; j <= 100; j++){
            if(power(x,i) == -1 || power(y,j) == -1) break;
            int k = power(x,i)*power(y,j);
            if(k > n) break;
            if((n%k) == 0) {
                st.insert(n/k);
            }
        }
    }
    cout << st.size() << nl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cout << power(10000000,1);
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}