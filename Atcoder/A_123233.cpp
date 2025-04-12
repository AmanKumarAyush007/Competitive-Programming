#include<bits/stdc++.h>
using namespace std;

#define int        int64_t
#define ff         first
#define ss         second
#define pb         push_back
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()

void solve(){
    string s;
    cin >> s;
    int n = s.size();
    bool flag = true;
    int cnt1 = 0, cnt2 = 0, cnt3 = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '1')cnt1++;
        if(s[i] == '2')cnt2++;
        if(s[i] == '3')cnt3++;
    }
    if(cnt1 != 1 || cnt2 != 2 || cnt3 !=3) flag = false;

    cout << (flag ? "Yes" : "No") ;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}