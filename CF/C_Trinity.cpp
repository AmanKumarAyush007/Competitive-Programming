#include<bits/stdc++.h>
using namespace std;

#define int        int64_t
#define ff         first
#define ss         second
#define pb         push_back
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()

void solve(){
    int n;
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> pq;
    priority_queue<int, vector<int>, greater<int>> pq1;

    int mx = 0;
    int mn = INT_MAX;

    for(int i = 0; i < n; i++){
        int ele;
        cin >> ele;
        mx = max(ele,mx);
        pq.push(ele);
        pq1.push(ele);
    }

    bool ck = true;
    int ans = 0;

    while(ck){
        int f = pq.top();
        pq.pop();
        int s = pq.top();
        if(f+s <= mx){
            pq.push(mx);
            ans++;
        }
        else ck = false;
    }

    bool ck1 = true;
    int ans1 = 0;

    while(ck){
        int f = pq.top();
        pq.pop();
        int s = pq.top();
        if(f+s <= mx){
            pq.push(mn);
            ans++;
        }
        else ck = false;
    }

    cout << ans << nl;
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