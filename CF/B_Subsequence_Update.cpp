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
    int n,x,y;
    cin >> n >> x >> y;
    int a[n];
    inp(a);
    vector<int> v,r,l;
    int sum = 0;
    x--,y--;
    for(int i = x; i <= y; i++){
        sum += a[i];
        v.pb(a[i]);
    }
    for(int i = 0; i < x; i++){
        l.pb(a[i]);
    }
    for(int i = y+1; i < n; i++){
        r.pb(a[i]);
    }

    sort(all(v));
    reverse(all(v)); // sort in descending
    if(v.size() >= 2){
        for(int i = 1; i < v.size(); i++){ // prefix sum or descending order sorted array
            v[i] = v[i] + v[i-1];
        }
    }


    if(x == 1 && y == n) cout << sum;       //range is of all ele
    else{
        int diff = 0;       // after reversing the subsequence the max diff occurs in the sum variable
        if(r.size()){       // check right side range 
            sort(all(r));
            if(r.size() >= 2){
                for(int i = 1; i < r.size(); i++){  // prefix sum or ascending order sorted array
                    r[i] = r[i] + r[i-1];   
                }
            }
            int k = min(r.size(),v.size());
            for(int i = 0; i < k; i++){
                diff = max(diff,v[i] - r[i]);
            }
        }
        if(l.size()){   //check right side of the given range
            sort(all(l));
            if(l.size() >= 2){
                for(int i = 1; i < l.size(); i++){  // prefix sum or ascending order sorted array
                    l[i] = l[i] + l[i-1];
                }
            }
            int k = min(l.size(),v.size());
            for(int i = 0; i < k; i++){
                diff = max(diff,v[i] - l[i]);
            }
        }
        cout << sum - diff; // subtract max diff that occur from either right side portion of the given range or left side
    }

    
    cout << nl;
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