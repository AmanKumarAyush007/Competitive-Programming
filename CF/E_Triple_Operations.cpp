#include<bits/stdc++.h>
using namespace std;

#define ll         long long
#define ff         first
#define ss         second
#define pb         push_back
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()


float log3(ll x) {
  return (double)log(x) / (double)log(3);
}

void solve(vector<int> lg){
    int a,b;
    cin >> a >> b;
    int ans = log3(a)+1;
    ans *= 2;

    ans += lg[b] - lg[a];
    
    cout << ans << nl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> lg(200005);
    for(int i = 1; i <= 200005; i++){
        lg[i] = log3(i)+1;
    }

    for(int i = 1; i <= 200005; i++){
        lg[i] += lg[i-1];
    }
    // for(auto &i : lg) cout << i << " " ;
    // cout << nl;


    int t = 1;
    cin >> t;
    while (t--)
    {
        solve(lg);
    }
    return 0;
}