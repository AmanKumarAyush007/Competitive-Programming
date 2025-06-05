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

const int MOD = 998244353;
const int MAX_N = 100000;
vector<int> pow2(MAX_N+1);

void precompute() {
    pow2[0] = 1;
    for(int i = 1; i <= MAX_N; i++) {
        pow2[i] = (pow2[i-1] * 2) % MOD;
    }
}

void solve(){
    int n;
    cin >> n;
    vector<int> p(n), q(n);
    inp(p)
    inp(q)

    vector<int> a(n), b(n);
    a[0] = 0;
    int cur_max_p = p[0];
    for(int i = 1; i < n; i++) {
        if(p[i] > cur_max_p) {
            cur_max_p = p[i];
            a[i] = i;
        } else {
            a[i] = a[i-1];
        }
    }

    b[0] = 0;
    int cur_max_q = q[0];
    for(int i = 1; i < n; i++) {
        if(q[i] > cur_max_q) {
            cur_max_q = q[i];
            b[i] = i;
        } else {
            b[i] = b[i-1];
        }
    }

    vector<int> r(n);
    for(int i = 0; i < n; i++) {
        int j1 = a[i];
        int k1 = i - j1;
        int exp1a = p[j1];
        int exp1b = q[k1];

        int j2 = b[i];
        int k2 = i - j2;
        int exp2a = q[j2];
        int exp2b = p[k2];

        int M1 = max(exp1a, exp1b);
        int m1 = min(exp1a, exp1b);
        int M2 = max(exp2a, exp2b);
        int m2 = min(exp2a, exp2b);

        if(M1 > M2) {
            r[i] = max((pow2[exp1a] + pow2[exp1b]) % MOD, (pow2[exp2a] + pow2[exp2b]) % MOD);
        } else if(M1 < M2) {
            r[i] = ;
        } else {
            if(m1 > m2) {
                r[i] = (pow2[exp1a] + pow2[exp1b]) % MOD;
            } else if(m1 < m2) {
                r[i] = (pow2[exp2a] + pow2[exp2b]) % MOD;
            } else {
                r[i] = (pow2[exp1a] + pow2[exp1b]) % MOD;
            }
        }
    }

    for(int i = 0; i < n; i++) {
        cout << r[i] << " ";
    }
    cout << nl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    precompute();
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}