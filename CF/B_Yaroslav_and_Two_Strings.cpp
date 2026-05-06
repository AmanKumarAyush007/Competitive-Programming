#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 1e9 + 7;
const int N = 1e5 + 5;

string s, t;
int dp[N][2][2];

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n >> s >> t;

    dp[0][0][0] = 1;

    for(int i = 0; i < n; i++){
        for(int condA = 0; condA < 2; condA++){
            for(int condB = 0; condB < 2; condB++){

                int cur = dp[i][condA][condB];
                if(cur == 0) continue;

                if(s[i] == '?' && t[i] == '?'){
                    // s > t
                    dp[i+1][1][condB] = (dp[i+1][1][condB] + cur * 45) % MOD;

                    // s < t
                    dp[i+1][condA][1] = (dp[i+1][condA][1] + cur * 45) % MOD;

                    // s == t
                    dp[i+1][condA][condB] = (dp[i+1][condA][condB] + cur * 10) % MOD;
                }
                else if(s[i] == '?'){
                    // s > t
                    dp[i+1][1][condB] = (dp[i+1][1][condB] + cur * ('9' - t[i])) % MOD;

                    // s < t
                    dp[i+1][condA][1] = (dp[i+1][condA][1] + cur * (t[i] - '0')) % MOD;

                    // equal
                    dp[i+1][condA][condB] = (dp[i+1][condA][condB] + cur) % MOD;
                }
                else if(t[i] == '?'){
                    // s > t
                    dp[i+1][1][condB] = (dp[i+1][1][condB] + cur * (s[i] - '0')) % MOD;

                    // s < t
                    dp[i+1][condA][1] = (dp[i+1][condA][1] + cur * ('9' - s[i])) % MOD;

                    // equal
                    dp[i+1][condA][condB] = (dp[i+1][condA][condB] + cur) % MOD;
                }
                else{
                    int newA = condA || (s[i] > t[i]);
                    int newB = condB || (s[i] < t[i]);

                    dp[i+1][newA][newB] = (dp[i+1][newA][newB] + cur) % MOD;
                }
            }
        }
    }

    cout << dp[n][1][1] << "\n";
}