#include<bits/stdc++.h>
using namespace std;

#define int        long long
#define ff         first
#define ss         second
#define pb         push_back
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()

void solve(){
    int x,y;
    cin >> x >> y;
    string s,q;
    cin >> s >> q;
    int n = s.size(),m = q.size();

    int a[26][n+1],b[26][m+1];

    for(int i = 0; i < 26; i++){
        for(int j = 0; j <= n; j++){
            a[i][j] = 0;
        }
    }
    for(int i = 0; i < 26; i++){
        for(int j = 0; j <= m; j++){
            b[i][j] = 0;
        }
    }
    

    for(int i = 0; i < n; i++){
        a[s[i]-'a'][i+1]++;
    }
    for(int i = 0; i < m; i++){
        b[q[i]-'a'][i+1]++;
    }

    for(int i = 0; i < 26; i++){
        for(int j = 1; j <= n; j++){
            a[i][j] += a[i][j-1];
        }
    }
    for(int i = 0; i < 26; i++){
        for(int j = 1; j <= m; j++){
            b[i][j] += b[i][j-1];
        }
    }


    while(y--){
        int p,q;
        cin >> p >> q;
        int ans = 0;
        int c[26];
        for(int i = 0; i < 26; i++){
            c[i] = a[i][q] - a[i][p-1];
        }

        int d[26];
        for(int i = 0; i < 26; i++){
            d[i] = b[i][q] - b[i][p-1];
        }


        for(int i = 0; i < 26; i++){
            if(c[i] < d[i]) ans+=d[i]-c[i];
        }

        cout << ans << nl;
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}