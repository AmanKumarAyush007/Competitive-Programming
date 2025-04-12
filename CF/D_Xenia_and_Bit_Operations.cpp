#include<bits/stdc++.h>
using namespace std;

// #define int        long long
#define ff         first
#define ss         second
#define pb         push_back
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()


class SgTree{
    vector<int> seg;
public:    
    SgTree (int n){
        seg.resize(4*n + 5);
    }

    void build(int ind, int low, int high, int a[],int orr){
        if(low == high) {
            seg[ind] = a[low];
            return;
        }
        
        int mid = (low+high)/2;

        build(2*ind+1,low,mid,a,!orr);
        build(2*ind+2,mid+1,high,a,!orr);
        
        if(orr) seg[ind] = seg[(2*ind)+2] | seg[(2*ind)+1];
        else seg[ind] = seg[(2*ind)+2] ^ seg[(2*ind)+1];

    }
    

    int query(int ind, int low, int high, int l, int r){
        if(r < low || l > high) return INT_MAX;
        if(l<=low && r >= high) return seg[ind];

        int mid = (low+high)/2;

        int left = query(2*ind+1,low,mid,l,r);
        int right = query(2*ind+2,mid+1,high,l,r);
        
        return min(left,right);
    }

    void update(int ind, int low, int high, int i, int val,int orr){

        if(low == high) {
            seg[ind] = val;
            return;
        }

        int mid = (low+high)/2;

        if(i <= mid)update(2*ind+1,low,mid,i,val,!orr);
        else update(2*ind+2,mid+1,high,i,val,!orr);

        if(orr) seg[ind] = seg[(2*ind)+2] | seg[(2*ind)+1];
        else seg[ind] = seg[(2*ind)+2] ^ seg[(2*ind)+1];
    }

    int ans(){
        return seg[0];
    }
};

void solve(){
    int n,m;
    cin >> n >> m;
    int el = pow(2,n);

    int a[el];
    for(auto &i : a) cin>>i;

    SgTree s(el);

    if(n%2 == 0) s.build(0,0,el-1,a,0);
    else s.build(0,0,el-1,a,1);

    while(m--){
        int i,val;
        cin >> i >> val;
        i--;
        if(n%2 == 0) s.update(0,0,el-1,i,val,0);
        else s.update(0,0,el-1,i,val,1);
        cout << s.ans() << nl;
    }

    
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n = 1;
    while(n--){
        solve();
    }
   
    return 0;
}