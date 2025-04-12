#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define pb push_back
#define nl '\n'
#define all(a) (a).begin(), (a).end()

bool check(double mid, double t)
{
    if ((sqrt(mid) + mid * mid) >= t)
        return true;
    return false;
}

double BinarySearch(double t)
{
    double lo = 1;
    double hi = t;
    double ans = 0;
    while (.0000001 <= hi - lo)
    {
        double mid = (lo + hi) / 2;
        if (check(mid, t))
        {
            ans = mid;
            hi = mid;
        }
        else
            lo = mid;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double t;
    cin >> t;

    double ans = BinarySearch(t);
    cout << setprecision(6);
    cout << ans << nl;

    return 0;
}