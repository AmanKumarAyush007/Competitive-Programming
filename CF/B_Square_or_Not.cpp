#include<bits/stdc++.h>
using namespace std;

#define ll         long long
#define ff         first
#define ss         second
#define pb         push_back
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()


bool isPerfectSquare(int num) {
    if (num < 0) {
        return false; // Negative numbers cannot be perfect squares
    }

    int sqrtNum = sqrt(num);
    return sqrtNum * sqrtNum == num;
}

void solve(){
    int n;
    cin >> n;
    string s;
    cin >>  s;
    if(!(isPerfectSquare(n))) cout << "No" ;
    else{
        int rt = sqrt(n);
        bool ck = true;
        for(int i = 0; i < rt; i++){
            if(s[i] != '1'){
                 ck = false;
                 break;
            }
            if(s[n-1-i] != '1') {
                 ck = false;
                 break;
            }
        }
        if(ck){
            for (int i = 0; i < n; i++)
            {
                if (i % rt == 0 ){
                    if(s[i] != '1'){
                        ck = false;
                        break;
                    }
                }
                else if (i % rt == rt - 1 ){
                    if(s[i] != '1'){
                        ck = false;
                        break;
                    }
                }
                else{
                    if(i>rt && i < n-rt && s[i] == '1'){
                        ck = false;
                        break;
                    }
                }
            }
        }

       if(ck) cout << "Yes";
       else cout << "No";
    }
    cout << nl;
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