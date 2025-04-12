#include<bits/stdc++.h>
using namespace std;

#define ll         long long
#define ff         first
#define ss         second
#define pb         push_back
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()

int digitSum(int n){
    int sum = 0;
    while(n){
        sum += n%10;
        n /= 10;
    }
    return sum;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a[200000];
    for(int i = 0; i < 200000; i++){
        a[i] = digitSum(i+1);
    }
    int presum[200000];
    presum[0] = a[0];
    for(int i = 1; i < 200000; i++){
        presum[i] = a[i]+presum[i-1];
    }

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int ans = presum[n-1];
        cout << ans << nl;
    }
    return 0;
}