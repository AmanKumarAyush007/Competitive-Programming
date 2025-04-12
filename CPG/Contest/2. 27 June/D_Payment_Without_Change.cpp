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
    ll a, b, n, s;
    cin >> a >> b >> n >> s;

    // only from 1 rs coin
    if (b >= s)
        cout << "YES" << nl;
    // only from Rs n coin
    else if (s % n == 0 and (s / n) <= a)
        cout << "YES" << nl;
    // from both Rs n coin and 1 rs coin
    else
    {
        int check = 0;
        ll hi = a;
        ll lo = 1;
        ll mid;
        while(hi>=lo){
            mid = (hi+lo)/2;
            if(((s-n*mid) >= 0) and(s-n*mid) <= b) {
                check = 1;
                break;
            }
            else lo = mid+1;
        }
        if (check == 1)
            cout << "YES" << nl;
        else
            cout << "NO" << nl;
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