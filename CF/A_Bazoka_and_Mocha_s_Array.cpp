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
    ll n;
    cin >> n;
    ll a[n];
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int is_sorted = 1;
    int start = -1;
    int end = -2;
    for (ll i = 0; i < n - 1; i++)
    {
        if (a[i] > a[i + 1])
        {
            is_sorted = 0;
            start = i + 1;
            end = i;
        }
    }
    if (is_sorted == 1)
    {
        cout << "Yes" << nl;
    }
    else
    {
        vector<ll> v;
        for (ll i = start; i < n; i++)
        {
            v.pb(a[i]);
        }
        for(ll i = 0; i <= end; i++){
            v.pb(a[i]);
        }
        // for(int i = 0; i < n; i++){
        //     cout<<v[i]<<" ";
        // }
        sort(a,a+n);
        int check = 1;
        for(int i = 0; i < n; i++){
            if(v[i]!=a[i]) {
                check = 0;
                break;
            }
        }
        if(check == 1) cout<<"Yes"<<nl;
        else cout<<"No"<<nl;
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