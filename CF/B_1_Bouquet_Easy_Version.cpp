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
    ll n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (auto &i : a) cin >> i;
        
    
    sort(a.begin(), a.end());
    
    ll sum = 0;
    ll temp = 0;
    ll left = 0;
    
    for (ll right = 0; right < n; right++) {
        temp += a[right];
        while(a[right] - a[left] > 1){
            temp -= a[left];
            left++;
        }
        while((temp > m)){
            temp -= a[left];
            left++;
        }
        sum = max(sum,temp);

    }
    
    cout << sum << endl;
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