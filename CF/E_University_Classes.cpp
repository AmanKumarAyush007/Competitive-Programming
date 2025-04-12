#include<bits/stdc++.h>
using namespace std;

#define ll         long long
#define ff         first
#define ss         second
#define pb         push_back
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()

void solve(){
    int n;
    cin >> n;
    map<int,int> mp;
    int ans = INT_MIN;
    while(n--){
        string s;
        cin >> s;
        for(int i = 0; i < 7; i++){
            if(s[i] == '1') mp[i]++;
            ans = max(ans,mp[i]);
        }
    }
    cout << ans;
    cout << nl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}