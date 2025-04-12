#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define pb push_back
#define endl '\n'
#define all(a) (a).begin(), (a).end()

void solve()
{
    int x, y, z;
    cin >> x >> y >> z;
    int sum = x + y + z;
    if (sum % 2 != 0)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << min(sum / 2, x + y) << endl;
    }
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