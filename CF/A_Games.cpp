#include<bits/stdc++.h>
using namespace std;

#define int        long long
#define ff         first
#define ss         second
#define pb         push_back
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()

void solve(){
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; ++i)
    {
        int a, b;
        cin >> a >> b;
        v[i] = {a, b};
    }
    int cont = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
            if (i != j)
            {
                if (v[i].first == v[j].second)
                    cont++;
            }
    }
    cout << cont << endl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}