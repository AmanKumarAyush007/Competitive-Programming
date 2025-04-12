#include<bits/stdc++.h>
using namespace std;

#define ll         long long
#define ff         first
#define ss         second
#define pb         push_back
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()

int diffSum(vector<int> &a){
    int n = a.size();
    int sum = 0;
    for(int i = 0; i < n-1; i++){
        sum += abs(a[i]-a[i+1]);
    }
    return sum;
}

void solve(){
    int n,x;
    cin>>n>>x;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    int mx = INT_MIN;

    for(int i = 0; i < n; i++){
        int temp = a[i];
        mx = max(diffSum(a),mx);
        // cout<<mx<<"! ";
        for(int j = 0; j < 2; j++){
            if(j == 0){
                a[i] = 1;
                mx = max(diffSum(a),mx);
        // cout<<mx<<"!! ";

            }
            else {
                a[i] = x;
                mx = max(diffSum(a),mx);
        // cout<<mx<<"!!! ";

            }
        }
        a[i] = temp;
    }
    cout<<mx<<nl;
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