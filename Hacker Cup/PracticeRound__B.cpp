#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define pb push_back
#define nl '\n'
#define all(a) (a).begin(), (a).end()

void solve()
{
    double  n,k;
    cin >> n >> k;
    double p_old = k/100.0;
    double pw =  ((n-1.0)/n);
    double p_new = pow(p_old , pw);

    
    double change = p_new - p_old;

    change *= 100;

    cout << setprecision(9);
    cout << change;

    cout << nl;
}

signed main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}