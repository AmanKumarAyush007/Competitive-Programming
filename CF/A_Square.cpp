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
    int a[8];
    int ans = INT_MIN;
    for (int i = 0; i < 8; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < 6; i++)
    {
        ans = max(ans, abs(a[i] - a[i + 2]));
    }
    cout << ans * ans << nl;
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