//Original Problem ->  Hamburger
// 

#include<bits/stdc++.h>
using namespace std;

#define int        long long
#define ff         first
#define ss         second
#define pb         push_back
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()

int check(int mid, int r, int ns, int nb, int nc, int ps, int pb, int pc, int s, int b, int c){
    s *= mid;
    b *= mid;
    c *= mid;

    s = max(0LL , (s-ns));
    b = max(0LL , (b-nb));
    c = max(0LL , (c-nc));

    s *= ps;
    b *= pb;
    c *= pc;

    int cost = s+b+c;

    return r >= cost;
    
}

void solve(){
    string st;
    cin >> st;
    int n = st.size();
    int nb,ns,nc;
    cin >> nb >> ns >> nc;
    int pb,ps,pc;
    cin >> pb >> ps >> pc;

    int r; cin >> r;
    
    int b = count(all(st),'B'), s = count(all(st),'S'), c = count(all(st),'C');

    int lo = 0;
    int hi = 1e13;

    int mid = (lo+hi)/2;
    int ans = 0;


    while(hi >= lo){
        mid = (lo+hi)/2;
        if(check(mid,r,ns,nb,nc,ps,pb,pc,s,b,c)) {
            ans = mid;
            lo = ans+1;
        }
        else hi = mid - 1;
    }


    cout << ans ;



    
    cout << nl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}