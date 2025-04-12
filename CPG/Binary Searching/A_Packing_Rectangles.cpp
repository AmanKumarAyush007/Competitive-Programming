#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define pb push_back
#define nl '\n'
#define all(a) (a).begin(), (a).end()

bool check(ll w, ll h, ll n, ll mid)
{
    ll a = mid/w;
    ll b= mid/h;
    return a >= n/b;
}

ll binarySearch(ll w, ll h, ll n)
{
    ll hi = 1e18;
    ll l = 0;
    ll mid = (l+hi)/2;   
    ll ans = 0;
    while(hi>=l){
        mid = (l+hi)/2;
        if(check( w,  h,  n, mid)){
            ans = mid;
            hi = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll w, h, n;
    cin >> w>>h>>n;

    ll ans = binarySearch( w,  h,  n);
    cout<<ans;


    return 0;
}