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
    int n, k;
    cin >> n >> k;
    int a[n];
    for (auto &i : a)
        cin >> i;
        
    sort(a, a + n,greater<int>());

    // for(auto &i : a) cout << i << " ";
    int rem = k;

    ll Ans = 0;

    for(int i = 0; i < n; i++){
        if(i % 2 == 0) Ans += a[i];
        else{
            int needed = min(rem, a[i - 1] - a[i]);
            a[i] += needed;
            rem -= needed;
            Ans -= a[i];
        }
    }



    cout << Ans;

    cout << nl;
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