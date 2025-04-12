#include<bits/stdc++.h>
using namespace std;

#define ll         long long
#define ff         first
#define ss         second
#define pb         push_back
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()

int f(int n){
    return (2*n)-1;
}

void solve(){
    int x,n;
    cin >> x >> n;
    int a[n];
    int count1 = 0; 
    int sum = 0;
    for(auto &i : a) {
        cin >> i;
        if(i == 1) count1++; 
    }
    if(count1 == n) cout << n-1 << nl;
    else
    {
        sort(a, a + n);
        for (int i = 0; i < n - 1; i++)
        {
            if (a[i] != 1)
                sum += f(a[i]);
        }
        int ans = count1 + sum;
        cout << ans << nl;
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