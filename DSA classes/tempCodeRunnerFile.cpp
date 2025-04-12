#include<bits/stdc++.h>
using namespace std;

#define int        int64_t
#define ff         first
#define ss         second
#define pb         push_back
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()

vector<int> countDistinct(vector<int> &arr, int k) {
       set<int> st;
       vector<int> v;
       int n = arr.size();
       int l = n - k + 1;
       for(int i = 0; i < k; i++){
           st.insert(arr[i]);
       }
       v.push_back(st.size());
       int j = 1;
       
       while(j < l){
           st.erase(arr[j-1]);
           st.insert(arr[j+k-1]);
           j++;
           v.push_back(st.size());
       }
       return v;
    }

// void solve(){
    
//     cout << nl;
// }

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // int n;cin >> n;
    int k; cin >> k;
    vector<int> v(n);
    for(auto &i : v) cin >> i;
    while(t--){
        int ans = countDistinct(v,k);
        cout << "ANS->" << ans;
    }
    return 0;
}