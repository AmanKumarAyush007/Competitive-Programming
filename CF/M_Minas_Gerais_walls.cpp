#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    int l = *min_element(x.begin(), x.end());
    int r = *max_element(x.begin(), x.end()) + k;
    int ans = l;
    while (l <= r) {
    	vector<int> a = x;
        int mid = (l + r) / 2;
		int ind = -1;
		for(int i=0;i<n;i++){
			if(a[i] < mid){
				ind = i;
				break;
			}
		}
		int val = mid-a[ind];
		if(val > k){
			r = mid-1;
			continue;
		}
		while(val<k && ind<n){
			a[ind]+=val;
			val++;
			ind++;
		}
		int flag = 1;
		for(int i=ind;i<n;i++){
			if(a[i] < mid){
				flag = 0;
				break;
			}
		}
        if(flag){
            ans = mid;
            l = mid + 1;
        } 
        else {
            r = mid - 1;
        }
    }
    cout << ans+1 << "\n";
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    while(t--){
    	solve();
	}
}