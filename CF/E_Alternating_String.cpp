#include<bits/stdc++.h>
using namespace std;

#define ll        long long
#define ff         first
#define ss         second
#define pb         push_back
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;

    if(n%2 == 0){
        map<char,int> mpOdd,mpEven;

        for(int i = 0; i < n; i++){
            if(i%2 == 0) mpEven[s[i]]++;
            else mpOdd[s[i]]++;
        }

        int sumOd = 0;
        int mxOD = INT_MIN;
        for(auto &[a,b] : mpOdd){
            sumOd+=b;
            mxOD = max(mxOD,b);
        }
        sumOd -= mxOD;

        int sumEV = 0;
        int mxEV = INT_MIN;
        for(auto &[a,b] : mpEven){
            sumOd+=b;
            mxEV = max(mxEV,b);
        }
        sumEV -= mxEV;

        cout << sumOd + sumEV;

    }
    else {
        
        vector<vector<ll>> PreOdd (26, vector<ll>(n,0));
        vector<vector<ll>> PreEven (26, vector<ll>(n,0));
        vector<vector<ll>> SuffOdd (26, vector<ll>(n,0));
        vector<vector<ll>> SuffEven (26, vector<ll>(n,0));

        for(int i = 0; i < n; i++){
            if(i%2 == 0){
                // char ch = s[i];
                PreEven[s[i] - 'a'][i]++;
                SuffEven[s[i] - 'a'][i]++;
            }
            else {
                PreOdd[s[i] - 'a'][i]++;
                SuffOdd[s[i] - 'a'][i]++;
            }
        }

        for(int i = 0; i < 26; i++){
            for(int j = 1; j < n; j++){
                PreEven[i][j] = PreEven[i][j] + PreEven[i][j-1];
                PreOdd[i][j] = PreOdd[i][j] + PreOdd[i][j-1];
            }
        }

        for(int i = 0; i < 26; i++){
            for(int j = n-2; j >= 0; j--){
                SuffEven[i][j] = SuffEven[i][j] + SuffEven[i][j+1];
                SuffOdd[i][j] = SuffOdd[i][j] + SuffOdd[i][j+1];
            }
        }

        ll ans = n;

        for(int i = 0; i < n; i++){
            if(i == 0){
                ll mxOd = 0;
                ll mxEv = 0;

                for(int j = 0; j < 26; j++){
                    mxOd = max(mxOd,SuffOdd[j][1]);
                    mxEv = max(mxEv,SuffEven[j][1]);
                }
                ans = min(ans, (n-(mxEv+mxOd)));

            }
            else if(i == n-1){
                ll mxOd = 0;
                ll mxEv = 0;

                for(int j = 0; j < 26; j++){
                    mxOd = max(mxOd,PreOdd[j][n-2]);
                    mxEv = max(mxEv,PreEven[j][n-2]);
                }
                ans = min(ans, (n-(mxEv+mxOd)));
            }
            else{
                ll mxOd = 0;
                ll mxEv = 0;

                for(int j = 0; j < 26; j++){
                    mxOd = max(mxOd,(SuffEven[j][i+1] + PreOdd[j][i-1]));
                    mxEv = max(mxEv,(SuffOdd[j][i+1] + PreEven[j][i-1]));
                }
                ans = min(ans, (n-(mxEv+mxOd)));
            }
        }

        if(n == 1) ans = 1;

        cout << ans;

    }
    
    cout << nl;
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