#include<bits/stdc++.h>
using namespace std;

#define ll         long long
#define ff         first
#define ss         second
#define pb         push_back
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    
    vector<int> a(n);
    vector<int> b(n);

    for(int &i : a) cin >> i;
    for(int &i : b) cin >> i;

    vector<int> c(n);

    for(int i = 0; i < n; i++){
        c[i] = a[i]-b[i];
    }

    sort(all(c));

    ll ans = 0;

    for(int i = 0; i < n; i++){
        if(c[i] <= 0) continue;
        int lb = lower_bound(all(c),(-c[i]+1)) - c.begin();
        ans += i-lb;
    }
    
    cout<<ans<<nl;
    return 0;
}