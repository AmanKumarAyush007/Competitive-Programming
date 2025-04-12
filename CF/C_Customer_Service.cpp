#include<bits/stdc++.h>
using namespace std;

#define int        int64_t
#define ff         first
#define ss         second
#define pb         push_back
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()
#define inp(v)     for(auto& x : v) cin >> x


void solve(){
    int n;
    cin >> n;
    int a[n][n];
    for(auto &i : a){
        for(auto &ele : i) cin >> ele;
    }
    

    vector<int> v(n,0);         // to store continuous 1's from back for each i 

    for(int i = 0; i < n; i++){  
        int cnt = 0;  
        for(int j = n-1; j >= 0; j--){
            if(a[i][j] == 1) cnt++;
            else break;
        }
        v[i] = cnt;
    }

    sort(all(v));

    int ans = 0;

    for(int i = 0; i < n; i++){
        if(v[i] >= ans+1) ans++;
    }
    // if v = {1,2,3,4,5}  then technically ans+1 = 6 but we also give on slot to 0 the the numbers which came in the mex array is 0,1,2,3,4. there ore max of the array is 5. 
    // if array a have n numbers, and we hav to find the mex of it give that zero is present then range of mex => (1 to n-1)
    // ans + 1 assures that it is greater than equal to 1
    // if all numbers from 0 to n-1 is present then mex must be n

    // sample: n = 4; 
    //                         x[i]
    // 6 7 8 1  => v[i] = 1 =>  1
    // 3 4 1 1  => v[i] = 2 =>  2
    // 9 1 1 1  => v[i] = 3 =>  3
    // 1 1 1 1  => v[i] = 4 =>  0
    // mex[0,1,2,3] = 4

    cout << min(n,(ans + 1)) << nl;         
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