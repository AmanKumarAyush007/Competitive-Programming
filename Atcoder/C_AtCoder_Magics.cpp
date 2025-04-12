#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define pb push_back
#define nl '\n'
#define all(a) (a).begin(), (a).end()

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    vector<ll> a;
    vector<ll> b;

    for (ll i = 0; i < t; i++)
    {
        ll a;
        ll b;
        cin >> a;
        cin >> b;
        pb(a);
        pb(b);
    }
    return 0;
}