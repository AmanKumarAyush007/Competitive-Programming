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
    vector<int> v(n);
    for(auto &i : v) cin >> i;
    sort(all(v),greater<int>());

    int x,a,y,b;
    cin >> x >> a >> y >> b;

    int k;
    cin >> k;

    if(y > x){              //to maintain that x > y && a > b
        swap(a,b);
        swap(x,y);
    }

    int com = lcm(a,b);

    int lo = 1;
    int hi = n;
    int ans = -1;

    while(hi >= lo){
        int mid = (lo + hi)/2;

        int m = 0;
        int sum = 0;

        vector<int> temp(n,0);

        for(int i = com - 1 ; i < mid; i += com){
            temp[i] = v[m];
            sum += (temp[i] * (x + y)) / 100;
            m++;
        }
        for(int i = a - 1 ; i < mid; i += a){
            if(temp[i]==0){
                temp[i] = v[m];
                sum += (temp[i] * (x)) / 100;
                m++;
            }
        }
        for(int i = b - 1 ; i < mid; i += b){
            if(temp[i]==0){
                temp[i] = v[m];
                sum += (temp[i] * (y)) / 100;
                m++;
            }
        }

        if(sum >= k){
            ans = mid;
            hi = mid - 1;
        }
        else lo = mid + 1;

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