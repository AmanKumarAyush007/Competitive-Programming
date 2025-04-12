#include<bits/stdc++.h>
using namespace std;

#define int        long long
#define ff         first
#define ss         second
#define pb         push_back
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()

void solve(){
    int n,m,k;
    cin >> n >> m >> k;
    string s;
    cin >> s;

    int cnt = 0;
    int count = 0;
    bool check =  true;

    for(int i = 0; i < n; i++){
        cnt++;
        if(s[i] == 'L') cnt = 0;                // if m = 1 and s = LWL then L to L jump krne ke liye 'm' ka min. value 2 i.e m > 1
        if(s[i] == 'W' && cnt >= m) count++;       //if cnt < m then bypass this
        if(s[i] == 'C' && cnt >= m) check = false;      //if cnt < m then bypass this
    }
    if(count > k) check = false;
    
    if(check) cout << "YES";
    else cout << "NO";
    
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