#include <bits/stdc++.h>
using namespace std;

#define int        int64_t
#define ff         first
#define ss         second
#define pb         push_back
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()
#define inp(v)     for(auto& x : v) cin >> x

void solve()
{
    int l, r;
    cin >> l >> r;
    int ind = -1;

    int a = 0, b = 0, c = 0;

    for (int i = 30; i >= 0; i--)
    {
        if (((1LL << i) & l) != ((1LL << i) & r))
        {
            ind = i;
            break;
        }

        if (((1LL << i) & l)) a |= (1LL << i), b |= (1LL << i);
            
    }

    a |= (1LL << ind);
    b |= ((1LL << ind) - 1);
    for(int i = l; i <= r; i++){
        if(i != a && i != b) {
            c = i;
            break;
        }
    }

    cout << a << " " << b << " " << c;
    cout << nl;
}

signed main()
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