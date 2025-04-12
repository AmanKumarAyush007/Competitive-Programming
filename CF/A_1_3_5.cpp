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
    int n;
    cin >> n;
    int x = n;
    int check = 0;
    while (n >= 5)
    {
        if (n % 5 == 0)
        {
            check = 1;
            break;
        }
        else
            n -= 3;
    }
    if (check == 1)
        {
            cout << 0 << nl;
            return ;
        }
    while (x >= 3)
    {
        if (x % 3 == 0)
        {
            check = 1;
            break;
        }
        else
            x -= 5;
    }
    if (check == 1)
        {
            cout << 0 << nl;
            return ;
        }
    else if (n % 3 == 0 or n % 5 == 0)
    {
        cout<<0<<nl;
    }
    else {
        cout<<min(n%3,n%5)<<nl;
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