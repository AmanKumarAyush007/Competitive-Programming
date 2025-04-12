#include<bits/stdc++.h>
using namespace std;

#define ll         long long
#define ff         first
#define ss         second
#define pb         push_back
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()

int sum(int n){
    int ans = 0;
    while(n!=0){
        ans += n%10;
        n/=10;
    }
    return ans;
}

void solve(){
    int n;
    cin >> n;
    if(n == 1) cout << 0;
    else{
        int count = 0;
        while(sum(n)%3 == 0 or ){

        }
        cout << sum(n);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}