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
        vector<int> v(n);
        set<int> s;
        for(int &i : v) {
            cin >> i;
            s.insert(i);
        }
        vector<int> uni(all(s));
        
        int mn = uni[0];
        int mn1;
        (uni.size() == 1) ? mn1 = uni[0] : mn1 = uni[1];
        for(int i = 1; i < uni.size() ; i++){
            if(uni[i] % mn != 0){
                mn1 = uni[i];
                break;
            }
        }
        int check = 1;
        for(int i = 0; i < n; i++){
            if(v[i] % mn != 0 and v[i] % mn1 != 0) check = 0;
        }
        if(check) cout<<"Yes"<<nl;
        else cout<<"No"<<nl; 
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