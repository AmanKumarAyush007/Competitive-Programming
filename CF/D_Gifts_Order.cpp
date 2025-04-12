#include<bits/stdc++.h>
using namespace std;

#define int        int64_t
#define ff         first
#define ss         second
#define pb         push_back
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()
#define inp(v)     for(auto& x : v) cin >> x

struct node
{
    int a,b,c,d,e;
};

class SGTree{
    vector<node> seg;

public:
    
    SGTree(int n){
        seg.resize(4*n);
    }

    void pr(){      //to debug
        for(auto &i : seg) cout << "{" << i.a << "," << i.b << "," << i.c << ","<< i.d <<"," << i.e << "} " << "\n"; 
        // cout << nl;
    }

    void build(int ind, int lo, int hi, int ar[]){
        if(lo == hi){
            seg[ind].a = ar[lo] + (lo+1);
            seg[ind].b = ar[lo] + (lo+1);
            seg[ind].c = ar[lo] - (lo+1);
            seg[ind].d = ar[lo] - (lo+1);
            seg[ind].e = 0;  // in base case the ans is 0
            return;
        }
        
        int mid = (lo + hi)/2;
        build(2*ind+1,lo,mid,ar);
        build(2*ind+2,mid+1,hi,ar);
        seg[ind].a = max(seg[2*ind+1].a,seg[2*ind+2].a);
        seg[ind].b = min(seg[2*ind+1].b,seg[2*ind+2].b);
        seg[ind].c = max(seg[2*ind+1].c,seg[2*ind+2].c);
        seg[ind].d = min(seg[2*ind+1].d,seg[2*ind+2].d);

        seg[ind].e = max(seg[2*ind+1].e,seg[2*ind+2].e);
        seg[ind].e = max(seg[ind].e,(seg[2*ind+1].a-seg[2*ind+2].b));
        seg[ind].e = max(seg[ind].e,(seg[2*ind+2].c-seg[2*ind+1].d));       
    }


    void update(int ind, int lo, int hi, int i, int val){
        if(lo == hi){
            seg[ind].a = val + (lo+1);
            seg[ind].b = val + (lo+1);
            seg[ind].c = val - (lo+1);
            seg[ind].d = val - (lo+1);
            seg[ind].e = 0;  // in base case the ans is 0
            return;
        }
        
        int mid = (lo + hi)/2;

        if(i <= mid) update(2*ind+1,lo,mid,i,val);
        else update(2*ind+2,mid+1,hi,i,val);

        seg[ind].a = max(seg[2*ind+1].a,seg[2*ind+2].a);
        seg[ind].b = min(seg[2*ind+1].b,seg[2*ind+2].b);
        seg[ind].c = max(seg[2*ind+1].c,seg[2*ind+2].c);
        seg[ind].d = min(seg[2*ind+1].d,seg[2*ind+2].d);

        seg[ind].e = max(seg[2*ind+1].e,seg[2*ind+2].e);
        seg[ind].e = max(seg[ind].e,(seg[2*ind+1].a-seg[2*ind+2].b));
        seg[ind].e = max(seg[ind].e,(seg[2*ind+2].c-seg[2*ind+1].d));       
    }

    

    int query() {
        return seg[0].e;
    }
};



void solve(){
    int n,k;
    cin >> n >> k;
    int a[n];
    inp(a);
    SGTree sg(n);
    sg.build(0,0,n-1,a);
    // sg.pr();
    cout << sg.query() << nl;
    // sg.update(0,0,n-1,4,4);
    // cout << sg.query() << nl;
    while(k--){
        int i,val;
        cin >> i >> val;
        i--;
        sg.update(0,0,n-1,i,val);
        cout << sg.query() << nl;
    }

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