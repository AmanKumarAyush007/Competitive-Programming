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
    int x, y;
    cin >> x >> y;
    int maxL = (5 / 2) * (3 / 2);
    int scL = (y + maxL - 1) / maxL;
    int ocL = 4 * y;

    int remL = scL * 15 - ocL;
    int remS = x - remL;
    int reqS;

    if (remS > 0)
    {
        reqS = (remS + 14) / 15;
    }
    else
    {
        reqS = 0;
    }

    int ans = scL + reqS;
    cout << ans << endl;
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