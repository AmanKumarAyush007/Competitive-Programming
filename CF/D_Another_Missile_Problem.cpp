#include<bits/stdc++.h>
using namespace std;

#define ll         long long
#define ff         first
#define ss         second
#define pb         push_back
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()

void solve(){
    int n,x;
    cin >> n >> x;

    double a[n];
    int b[n];

    for(auto &i : a) cin >> i;
    for(auto &i : b) cin >> i;

    double total = 0;

    for(int i = 0; i < n; i++){
        if(b[i] >= x) total += a[i];
        else a[i] = 0;
    }


    cout << fixed << setprecision(9) ;

    for(int i = 0; i < n; i++){
        cout  << a[i]/total << " ";
    }



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