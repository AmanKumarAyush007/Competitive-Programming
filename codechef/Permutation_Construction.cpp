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
    if(n%2 == 1){
        int st = 1;
        for(int i = 0; i < n; i+=2){
            a[i] = st;
            st++;
        }
        for(int i = 1; i < n; i+=2){
            a[i] = st;
            st++;
        }
    }
    else{
        int st = 1;
        for(int i = 0; i < n; i+=2){
            a[i] = st;
            st++;
        }
        for(int i = n-1; i >= 1; i-=2){
            a[i] = st;
            st++;
        }
    }
    for(auto &i : a) cout << i << " ";
    cout << nl;
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