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


const int MOD = 1e9 + 7;

vector<int> fact;
vector<int> inv_fact;

int power(int base, int exp, int mod) {
    int res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) res = res * base % mod;
        base = base * base % mod;
        exp /= 2; 
    }
    return res;
}
int modInverse(int n, int mod) {
    return power(n, mod - 2, mod);
}
void precompute(int n) { 
    fact.resize(n + 1);
    inv_fact.resize(n + 1);

    fact[0] = 1;
    for (int i = 1; i <= n; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }

    inv_fact[n] = modInverse(fact[n], MOD);
    for (int i = n - 1; i >= 0; i--) {
        inv_fact[i] = (inv_fact[i + 1] * (i + 1)) % MOD;
    }
}
int ncr( int N, int r ) {
    if (r == 0) return 1;
    int Nmod = N % MOD;
    int nmod = (Nmod + (r - 1)) % MOD;
    if (nmod < r) return 0; 
    int num = 1;
    for (int i = 0; i < r; ++i) {
        int ch = (nmod - i) % MOD;
        if (ch < 0) ch += MOD;
        num = ( num * ch ) % MOD;
    }
    int res = ( ( num * inv_fact[r] ) % MOD );
    return res;
}

vector<pair<int,int>> factorize(int x) {
    vector<pair<int,int>> res;
    for (int p = 2; p * p <= x; p++) {
        if (x % p == 0) {
            int cnt = 0;
            while (x % p == 0) {
                x /= p;
                ++cnt;
            }
            res.push_back({p, cnt});
        }
    }
    if (x > 1) res.push_back({x, 1});
    return res;
}

int nglo;
int aglo;
vector<pair<int,int>> facs;
int rglo;
int ans;

void dfs(int idx, int curD, vector<int>& svec) {
    if (idx == rglo) {
        if (curD <= aglo) {
            int prod = 1;
            for (int j = 0; j < rglo; ++j) {
                int sj = svec[j];
                int ej = facs[j].second;
                int tj = ej - sj;

                int c1 = ncr(nglo, sj);
                if (c1 == 0) { prod = 0; break; }
                
                int c2 = ncr(nglo, tj);
                if (c2 == 0) { prod = 0; break; }

                prod = prod * c1 % MOD;
                prod = prod * c2 % MOD;
            }

            ans += prod;
            if (ans >= MOD) ans -= MOD;
        }
        return;
    }

    int p = facs[idx].ff;
    int e = facs[idx].ss;
    int val = 1;

    for (int s = 0; s <= e; ++s) {
        svec[idx] = s;
        if (curD > aglo) {
            break;
        }
        dfs(idx + 1, curD, svec);
        if (s < e) {
            if (curD > aglo / p) {
                curD = aglo + 1;
            } else {
                curD *= p;
            }
        }
    }
}

void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    nglo = n;
    aglo = a;
    facs = factorize(b);
    rglo = (int)facs.size();
    ans = 0;

    vector<int> svec(max(1LL, rglo), 0);
    dfs(0, 1, svec);

    cout << (ans % MOD) << nl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int max_n = 100000; 
    precompute(max_n); 

    #ifndef ONLINE_JUDGE
    freopen("final_product_chapter_2_input.txt", "r", stdin);
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


