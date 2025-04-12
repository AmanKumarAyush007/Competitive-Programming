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
    int a[n],b[n];
    for(auto &i : a) cin >> i;
    for(auto &i : b) cin >> i;
   
    int ans1 = 0;
    int ans2 = 0;
    int count1 = 0;
    int count2 = 0;

    for(int i = 0; i < n; i++){
        if((a[i] == 0 and b[i] == -1) or (b[i] == 0 and a[i] == -1)) continue;
        else if(a[i] == 1 and ((b[i] == 0) or (b[i] == -1))) ans1++;
        else if(b[i] == 1 and ((a[i] == 0) or (a[i] == -1))) ans2++;
        else if((a[i] == -1) and (b[i] == -1) ) count2++;
        else if((a[i] == 1) and (b[i] == 1) ) count1++;
    }

    // cout << ans1 << ans2 << count1 << count2;


    while(count1--){
        if(ans1 >= ans2) ans2++;
        else ans1++;
    }

    while(count2--){
        if(ans1 >= ans2) ans1--;
        else ans2--;
    }

    cout << min(ans1,ans2) << nl;


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