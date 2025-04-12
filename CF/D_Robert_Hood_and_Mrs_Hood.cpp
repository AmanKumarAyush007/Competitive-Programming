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
    int d,k;
    cin >> d >> k;
    vector<int> diff(n+2, 0);

    while(k--){
        int l,r;
        cin >> l >> r;

        int newL = max(1LL,l-d+1);
        int newR = min(n-d+1, r);

        diff[newL]++;
        diff[newR+1]--;
    }

    for(int i = 1; i <= n; i++){
        diff[i] += diff[i-1];
    }

    int mother = 1e18, brother = -1;
    int ansM = 0, ansB = 0;

    for(int i = 1; i <= n-d + 1; i++){
        int curr = diff[i];
        if(curr < mother) {
            mother = curr;
            ansM = i;
        }
        if(curr > brother) {
            brother = curr;
            ansB = i;
        }
    }

    cout << ansB << " " << ansM;

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