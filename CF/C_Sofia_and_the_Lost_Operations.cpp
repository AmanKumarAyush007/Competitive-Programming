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
    // must use ll
    ll n;
    cin >> n;
    ll a[n];
    vector<ll> b(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (ll i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    ll m;
    cin >> m;
    ll d[m];
    for (ll i = 0; i < m; i++)
    {
        cin >> d[i];
    }
    map<ll, ll> mp, mp1;
    for (ll i = 0; i < n; i++)
    {
        if (a[i] != b[i])
            mp[b[i]]++;
    }
    for (ll i = 0; i < m; i++)
    {
        mp1[d[i]]++;
    }
    int check = 1;
    for (auto [x, y] : mp)
    {
        if (mp1[x] < y)
        {
            check = 0;
        }
    }
    if (count(b.begin(), b.end(), d[m - 1]) == 0)
        check = 0;
    if (check) cout << "YES" << nl;
    else cout << "NO" << endl;
        
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}