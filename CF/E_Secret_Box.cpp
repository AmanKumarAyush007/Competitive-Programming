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
    ll a, b, c,k;
    cin >> a >> b >> c >> k;
    ll x,maxx = 0;
    for(ll i = 1; i <= a; i++){
        for(ll j = 1; j <= b; j++){
            ll ij = i*j;
            if(k%ij == 0 and c>=k/ij){
                x=k/ij;
                maxx = max(maxx,(a-i+1)*(b-j+1)*(c-x+1));
            }
        }
    }
    cout<<maxx<<nl;
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