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
    int a[n];
    int check = 0;
    int sum = 0;
    for(int &i : a){
        cin >> i;
        sum += i;
    }
    for(int &i : a){
        if((sum-i)%3 == 0) {
            check = 1;
        }  
    }
    if(sum%3 == 0) cout << sum%3 << nl;
    else if(sum%3 == 2) cout<<1<<nl;
    else{
        if(check) cout<<1<<nl;
        else cout<<2<<nl;
    }

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