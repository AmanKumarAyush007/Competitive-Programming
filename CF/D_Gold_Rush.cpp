#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define pb push_back
#define nl '\n'
#define all(a) (a).begin(), (a).end()

bool check(int n, int m)
{
    if (n == m) return true;
    if (n < m) return false;
    if (n % 3 != 0) return false;
        
    return (check(2 * (n / 3), m) || check((n / 3), m));
}

void solve()
{
    int n, m;
    cin >> n >> m;
    if(check(n,m)) cout<<"YES"<<nl;
    else cout<<"NO"<<nl;
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