#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define pb push_ back

void solve()
{
    ll n;
    cin >> n;
    ll a[n];
    ll pre[n];
    ll sum = 0;
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
        pre[i] = sum;
    }
    ll q;
    cin >> q;
    while (q--)
    {
        ll q1, q2;
        cin >> q1 >> q2;
        if (q1 == 1)
        {
            cout << pre[q2 - 1] << endl;
        }
        else
        {
            cout << pre[q2 - 1] - pre[q1 - 2] << endl;
        }
    }
}

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}