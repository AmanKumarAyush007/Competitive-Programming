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
    string s = "VIBGYOR";
    string s1 = "GYOR";

    int i = 0;

    int rem = n - 7;

    string ans = s;

    while(rem>0){
        rem--;
        ans += s1[i];
        i++;
        i %= 4;
    }

    cout << ans;


    cout << nl;
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