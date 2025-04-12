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
    int ans = INT_MAX;
    int a[5] = {1, 3, 6, 10, 15};

    int i = 4,j = 4;
    int num = n;
    for(int i = 4; i >= 0; i--){
        int curr = 0;
        n = num;
        for(int j = i; j >= 0; j--){
            curr += n/a[j];
            n %= a[j];
        }
        ans = min(ans,curr);
    }

    cout << ans << nl;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}