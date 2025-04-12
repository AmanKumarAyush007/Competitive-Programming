#include<bits/stdc++.h>
using namespace std;

#define ll         long long
#define ff         first
#define ss         second
#define pb         push_back
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()

void solve(){
    int n,q;
    cin >> n >> q;
    int a[n];
    multiset<int> st;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        st.insert(a[i]);
    }
    for(int i = 0; i < q; i++){
        string s;
        cin >> s;
        int k;
        cin >> k;
        if(s == "DEL"){
            st.erase(st.find(k));
        }
        else st.insert(k);

        cout << *st.rbegin() - *st.begin() << endl;
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}