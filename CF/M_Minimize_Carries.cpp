#include<bits/stdc++.h>
using namespace std;

#define int        long long
#define ff         first
#define ss         second
#define pb         push_back
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()

vector<int> dig(int x){
    vector<int> ans;
    while(x > 0){
        int d = x%10;
        x /= 10;
        ans.pb(d);
    }
    // reverse(all(ans));
    return ans;
}

int f(int sum, int x){
    vector<int> sm = dig(sum);
    vector<int> X = dig(x);
    int carry = 0;
    int ans = 0;

    for(int i = 0; i < X.size(); i++){
        if(X[i] + sm[i] + carry > 9){
            carry = 1;
            ans++;
        }
        else carry = 0;
    }
    return ans;

}

void solve(){
    int n;
    cin >> n;
    int a[n];
    for(auto &i : a)cin >> i;
    if(n == 1) cout << 0;
    else {
        sort(a,a+n,greater<int>());
        int sum = a[0];
        int ans = 0;
        for(int i = 1; i < n; i++){
            ans += f(sum,a[i]);
            sum += a[i];
        }
        cout << ans;

        // vector<int> k=  dig(a[0]);
        

        // for(auto &i : a) cout << i << " ";

        // for(int i = 0; i < k.size(); i++){
        //     cout << k[i] << " ";
        // }

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