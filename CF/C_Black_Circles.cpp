#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define pb push_back
#define nl '\n'
#define all(a) (a).begin(), (a).end()

void solve()
{
    ll n;
    cin >> n;
    ll min_dis = std::numeric_limits<long long>::max();  //max value of long long just like of INT_MAX for int 
    vector<pair<ll, ll>> vp;

    for (int i = 0; i < n; i++)
    {
        ll a, b;
        cin >> a >> b;
        vp.pb({a, b});
    }

    ll x, y, p, q;
    cin >> x >> y >> p >> q;

    ll dis = (x - p) * (x - p) + (y - q) * (y - q);

    for (int i = 0; i < n; i++)
    {
        min_dis = min(((vp[i].ff - p) * (vp[i].ff - p) + (vp[i].ss - q) * (vp[i].ss - q)), min_dis);
        // min_dis = min(temp, min_dis);
    }

    // cout <<min_dis <<  " " << dis << nl;

    if(min_dis <= dis) cout << "NO" << nl;
    else cout << "YES" << nl;
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