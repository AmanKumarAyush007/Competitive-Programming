#include <bits/stdc++.h>
using namespace std;

#define int int64_t

class DisjointSet{
    

    public:
    vector<int>rank,parent,size;
    
    DisjointSet(int n){
        rank.resize(n+1,0);
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i=1;i<=n;i++){
            parent[i]=i;
        }
    }

    int findulp(int node){
        if(node==parent[node]){
            return node;
        }
        return parent[node]=findulp(parent[node]);
    }

    void ubr(int u,int v){
       int upu=findulp(u);
       int upv=findulp(v);

       if(upu==upv){return;}

       if(rank[upu]<rank[upv]){
        parent[upu]=upv;
       }
       else if(rank[upu]>rank[upv]){
        parent[upv]=upu;
       }
       else{
        parent[upu]=upv;
        rank[upv]++;
       }
    }


    void ubs(int u,int v){
       int upu=findulp(u);
       int upv=findulp(v);

       if(upu==upv){return;}

       if(size[upu]<=size[upv]){
        parent[upu]=upv;
        size[upv]+=size[upu];
       }
       else if(size[upu]>size[upv]){
        parent[upv]=upu;
        size[upu]+=size[upv];
       }
    }

};

void solve(int &ans) {
   int n,m,s;
   cin>>n>>m>>s;

   vector<vector<char>>a(n,vector<char>(m));

   vector<vector<int>>c(n,vector<int>(m,0)),pre(n+1,vector<int>(m+1,0));

   

   for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        cin>>a[i][j];
        c[i][j]=i*m+(j+1);
        pre[i+1][j+1]=pre[i+1][j]+(a[i][j]=='#');
    }
   }

   vector<vector<int>>g(n,vector<int>(m,0));

   DisjointSet st(n*m);

   int maxi=0;

   for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        if(i+s>=n||j+s>=m||i-s<0||j-s<0||a[i][j]=='#'){
            continue;
        }
        bool f=0;
        int x=s;
        for(int dl=0;dl<=s;dl++){
            if(pre[i+dl+1][j+1+x]-pre[i+dl+1][j-x]>0){
                f=1;
                break;
            }
            x--;
        }
        x=0;
        for(int dl=-s;dl<=0;dl++){
            if(pre[i+dl+1][j+1+x]-pre[i+dl+1][j-x]>0){
                f=1;
                break;
            }
            x++;
        }


        if(!f){
            //cout<<i+1<<" "<<j+1<<endl;
            g[i][j]=1;
            if(g[i-1][j]){
                st.ubs(c[i][j],c[i-1][j]);
            }
            if(g[i][j-1]){
                st.ubs(c[i][j],c[i][j-1]);
            }

            maxi=max(maxi,st.size[st.findulp(c[i][j])]);
        }
    }
   }

   ans=maxi;


   //cout<<maxi<<endl;

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int t;
    cin >> t;

    int ans;
    for(int i=1;i<=t;i++){
        solve(ans);
        cout<<"Case #"<<i<<":"<<" "<<ans<<endl;
    }
    return 0;
}