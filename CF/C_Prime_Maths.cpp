#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define pb push_back
#define nl '\n'
#define all(a) (a).begin(), (a).end()

vector<pair<int, int>> primeFactorization(int n) {
    vector<pair<int, int>> factors;
    for (int i = 2; i * i <= n; ++i) {
        int count = 0;
        while (n % i == 0) {
            n /= i;
            count++;
        }
        if (count > 0) {
            factors.push_back({i, count});
        }
    }
    if (n > 1) {
        factors.push_back({n, 1});
    }
    return factors;
}

void solve()
{

    int n;
    cin >> n;
    

    vector<pair<int, int>> vp = primeFactorization(n);

    for(auto &[a,b] : vp) swap(a,b);

    sort(all(vp),greater<pair<int,int>>());

    int pre[vp.size()];

    for(int i = 0; i < vp.size(); i++){
        if(i == 0) pre[i] = vp[i].ss;
        else pre[i] = pre[i-1] * vp[i].ss;
    }

    int i = vp.size() - 1;

    int ans = 0;

    while(i>=0){
        if(vp[i].ff <= 0) i--;
        else{
            ans += pre[i];
            for(int j = 0; j < vp.size(); j++){
                vp[j].ff--;
            }
        }
    }

    cout << ans;
    cout << nl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}