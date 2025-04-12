#include<bits/stdc++.h>
using namespace std;

#define ll         long long
#define ff         first
#define ss         second
#define pb         push_back
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()

void solve(){
    string s;
    cin>>s;
  
    int count = 0;
    stack<char> st;
    for(auto c : s){
        if(st.empty() or st.top() != c){
            st.push(c);
        }
        else{
            count++;
            st.pop();
        }
    }
    if(count%2 == 0) cout<<"No"<<endl;
    else cout<<"Yes"<<endl;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
