#include<bits/stdc++.h>
using namespace std;

#define int        long long
#define ff         first
#define ss         second
#define pb         push_back
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()

void solve(){
    string s;
    cin >> s;
    int n = s.size();
    int cur = 1,cnt = 0;                
    for(int i = 0; i < n; i++){
        if(s[i]==s[i+1]) cur++;
        else cur = 1;
        cnt = max(cnt,cur);
    }
    cout <<cnt<< nl;
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