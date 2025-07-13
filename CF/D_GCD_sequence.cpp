#include<bits/stdc++.h>
using namespace std;

#define ll         long long
#define ff         first
#define ss         second
#define pb         push_back
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()

void solve(){
    ll n;
    cin>>n;
    vector<int> a(n);
    for(ll i = 0; i < n; i++){
        cin>>a[i];
    }
    vector<int> v;
    for(int i = 0; i < n-1; i++){
        int g = __gcd(a[i],a[i+1]);
        v.pb(g);
    }
    int cnt = 0;
    for(int i = 0; i < v.size()-1; i++){
        if(v[i] > v[i+1]) cnt++;
    }

    if(cnt == 0) cout << "YES\n";
    else {
        vector<int> ch(v.begin(),prev(v.end()));

        if(is_sorted(all(ch))){
            cout << "YES\n";
            return;
        }

        vector<int> ch1(v.begin()+1,v.end());

        if(is_sorted(all(ch1))){
            cout << "YES\n";
            return;
        }

        vector<int> pre(n-1,1), post(n-1,1);
        for(int i = 1; i < v.size(); i++){
            pre[i] = pre[i-1] & (v[i-1] <= v[i]);
        }
        for(int i = v.size()-2; i >= 0; i--){
            post[i] = post[i+1] & (v[i] <= v[i+1]);
        }



        for(int i = 1; i < a.size()-1; i++){
            v[i] = gcd(a[i-1],a[i+1]);
            v[i-1] = v[i];


            bool check = true;
            

            if((i-2 >= 0)&& (v[i-2] > v[i-1])) check = false;
            if((i+1 < v.size() && v[i+1] < v[i])) check = false;

            if(i-2 >= 0 && pre[i-2] == 0) check = false;
            if((i+1 < v.size() && post[i+1] == 0)) check = false;



            if(check){
                cout << "YES\n";
                return;
            }
            v[i-1] = gcd(a[i-1],a[i]);
            v[i] = gcd(a[i],a[i+1]);
        }

        cout << "NO\n";
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