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
    int a, b;
    cin >> a >> b;
    int sum = 1 * a + 2 * b;
    if (sum % 2 != 0)
        cout << "NO" << nl;
    else
    {
        for (int i = 0; i <= a; i++)
        {
            for (int j = 0; j <= b; j++)
            {
                if(1*i + 2*j == (sum/2)){
                    cout << "YES" << nl;
                    return;
                }
            }
        }
        cout << "NO" << nl;
    }

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