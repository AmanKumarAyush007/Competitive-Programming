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
    if(n>1 && n <= 3) {
        cout << "NO SOLUTION";
        return;
    }
    else if (n == 4){
        cout << 3 << " " << 1 << " " << 4 <<" " << 2;
        return;
    }
    vector<int> v(n);
    int ele = 1;

    for(int i = 0; i < n; i+=2){
        v[i] = ele++;
    }
    for(int i = 1; i < n; i+=2){
        v[i] = ele++;
    }

    for(int i = 0; i < n; i++){
        cout << v[i] << " ";
    }
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