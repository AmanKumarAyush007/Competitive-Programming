#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ff first
#define ss second
#define pb push_back
#define endl '\n'

void preprocess(ll &s, ll &x, ll &y, vector<vector<vector<ll>>> &grid, ll &c)
{
    for (ll i = 0; i < 11; i++)
    {
        grid[i][x][y] += s;
        s = (s + 1) % (c + 1);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, q, c;
    cin >> n >> q >> c;

    vector<vector<vector<ll>>> grid(11, vector<vector<ll>>(105, vector<ll>(105)));
    for (int i = 0; i < 11; i++)
    {
        for (int j = 0; j < 105; j++)
        {
            for (int k = 0; k < 105; k++)
            {
                grid[i][j][k] = 0;
            }
        }
    }

    while (n--)
    {
        ll x, y, s;
        cin >> x >> y >> s;
        preprocess(s, x, y, grid, c);
    }

    while (q--)
    {
        ll t, x1, y1, x2, y2;
        cin >> t >> x1 >> y1 >> x2 >> y2;
        ll sum = 0;

        t = t % (c + 1);

        for (ll i = x1; i <= x2; i++)
        {
            for (ll j = y1; j <= y2; j++)
            {
                sum += grid[t][i][j];
            }
        }

        cout << sum << endl;
    }

    return 0;
}