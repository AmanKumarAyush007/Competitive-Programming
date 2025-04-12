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
    vector<int> a(2 * n);
    for (int &i : a)
        cin >> i;
    ll ans = 0;
    sort(a.begin(), a.end());

    for(int i = 0; i < 2*n; i+=2)
    {   
        ans += a[i];
    }   
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