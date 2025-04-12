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
    ll n, k, q;
    cin >> n >> k >> q;
    vector<ll> a(k);
    vector<ll> b(k);
    vector<ll> c(q);

    for (ll i = 0; i < k; i++)
    {
        cin >> a[i];
    }
    for (ll i = 0; i < k; i++)
    {
        cin >> b[i];
    }

    // vector<double> s;
    // double f = static_cast<double>(a[0]) / static_cast<double>(b[0]);
    // s.pb(f);
    if (k != 1)
    {
        // for (ll j = 0; j < k - 1; j++)
        // {
        //     s.pb(static_cast<double>(a[j + 1] - a[j]) / static_cast<double>(b[j + 1] - b[j]));
        // }

        for (ll i = 0; i < q; i++)
        {
            int c;
            cin >> c;
            if (c[i] == 0)
                cout << 0 << " ";

            else
            {
                auto it = lower_bound(all(a), c[i]);
                if (*it == c[i])
                {
                    int indx = distance(a.begin(), it);
                    cout << b[indx] << " ";
                }
                else
                {
                    int index = distance(a.begin(), it);
                    cout << index << "!";
                    if (index == 0)
                    {
                        int sol = (c[i] * b[0]) / a[0];
                        cout << sol << " ";
                    }
                    else
                    {
                        int ans = b[index - 1] + (((c[i] - a[index - 1]) * ((1.0l * b[index] - b[index - 1])) / (a[index] - a[index - 1])));
                        cout << ans << "!!" << " ";
                    }
                }
            }
        }
    }
    else
    {
        for (ll i = 0; i < q; i++)
        {
            // double p = static_cast<double>(c[i]);
            // double m = p / s[0];
            int sol = (c[i] * b[0]) / a[0];
            cout << sol << " ";
        }
    }
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}