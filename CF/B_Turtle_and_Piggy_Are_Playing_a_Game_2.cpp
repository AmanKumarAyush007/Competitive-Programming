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
    for(auto &i : a) cin >> i;
    sort(a,a+n);
    deque<int> dq;
    for(int i = 0; i < n; i++){
        dq.pb(a[i]);
    }
    int i = 0;
    while(dq.size()!=1){
        if(i%2 == 0) dq.pop_front();
        else dq.pop_back();
        i++;
    }
    cout << dq.front() << nl;
        
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