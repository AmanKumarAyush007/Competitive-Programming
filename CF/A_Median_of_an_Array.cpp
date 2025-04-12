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
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    int indx;
    int ans = 0;
    
    (n%2!=0) ? indx = n / 2 : indx = (n-1) / 2;
    for (int i = indx ; i < n; i++)
    {
        if (a[indx] == a[i])
            ans++;
        else
            break;
    }
    cout<<ans<<nl;
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