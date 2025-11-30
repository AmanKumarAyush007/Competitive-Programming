#include<bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define debug(x...)
#endif
#define int long long
#define nl '\n'

void solve(){
    int n;
    cin>>n;

    vector<int>a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];

    vector<int>b(n+1);
    for(int i=1;i<=n;i++) cin>>b[i];

    if(n<=20){
        int best=LLONG_MAX;

        for(int m=0;m<(1<<n);m++){
            bool ok=true;

            for(int i=1;i<=n && ok;i++){
                if(b[i]>0){
                    bool sat=false;
                    for(int e=b[i];e<=i && !sat;e++){
                        int s=e-b[i]+1;
                        if(s<1) continue;
                        bool good=true;
                        for(int k=s;k<=e;k++){
                            if(!(m&(1<<(k-1)))){ good=false; break; }
                        }
                        if(good) sat=true;
                    }
                    if(!sat) ok=false;
                }
            }

            if(ok){
                int c=0;
                for(int i=1;i<=n;i++) if(m&(1<<(i-1))) c+=a[i];
                best=min(best,c);
            }
        }

        cout<<best<<nl;
        return;
    }

    int ans=LLONG_MAX;

    {
        vector<bool>on(n+1,false);
        for(int i=1;i<=n;i++){
            if(b[i]>0){
                bool sat=false;
                for(int e=b[i];e<=i && !sat;e++){
                    int s=e-b[i]+1;
                    bool good=true;
                    for(int k=s;k<=e;k++){
                        if(!on[k]){ good=false; break; }
                    }
                    if(good) sat=true;
                }
                if(!sat){
                    int mn=LLONG_MAX,be=-1;
                    for(int e=b[i];e<=i;e++){
                        int s=e-b[i]+1;
                        int c=0;
                        for(int k=s;k<=e;k++){
                            if(!on[k]) c+=a[k];
                        }
                        if(c<mn){ mn=c; be=e; }
                    }
                    int s=be-b[i]+1;
                    for(int k=s;k<=be;k++) on[k]=true;
                }
            }
        }
        int tot=0;
        for(int i=1;i<=n;i++) if(on[i]) tot+=a[i];
        ans=min(ans,tot);
    }

    {
        vector<pair<int,int>>v;
        for(int i=1;i<=n;i++) if(b[i]>0) v.push_back({b[i],i});
        sort(v.rbegin(),v.rend());

        vector<bool>on(n+1,false);
        for(auto &p:v){
            int len=p.first,pos=p.second;
            bool sat=false;

            for(int e=len;e<=pos && !sat;e++){
                int s=e-len+1;
                bool good=true;
                for(int k=s;k<=e;k++){
                    if(!on[k]){ good=false; break; }
                }
                if(good) sat=true;
            }

            if(!sat){
                int mn=LLONG_MAX,be=-1;
                for(int e=len;e<=pos;e++){
                    int s=e-len+1;
                    int c=0;
                    for(int k=s;k<=e;k++){
                        if(!on[k]) c+=a[k];
                    }
                    if(c<mn){ mn=c; be=e; }
                }
                int s=be-len+1;
                for(int k=s;k<=be;k++) on[k]=true;
            }
        }

        int tot=0;
        for(int i=1;i<=n;i++) if(on[i]) tot+=a[i];
        ans=min(ans,tot);
    }

    {
        vector<pair<int,int>>v;
        for(int i=1;i<=n;i++) if(b[i]>0) v.push_back({b[i],i});
        sort(v.begin(),v.end());

        vector<bool>on(n+1,false);
        for(auto &p:v){
            int len=p.first,pos=p.second;
            bool sat=false;

            for(int e=len;e<=pos && !sat;e++){
                int s=e-len+1;
                bool good=true;
                for(int k=s;k<=e;k++){
                    if(!on[k]){ good=false; break; }
                }
                if(good) sat=true;
            }

            if(!sat){
                int mn=LLONG_MAX,be=-1;
                for(int e=len;e<=pos;e++){
                    int s=e-len+1;
                    int c=0;
                    for(int k=s;k<=e;k++){
                        if(!on[k]) c+=a[k];
                    }
                    if(c<mn){ mn=c; be=e; }
                }
                int s=be-len+1;
                for(int k=s;k<=be;k++) on[k]=true;
            }
        }

        int tot=0;
        for(int i=1;i<=n;i++) if(on[i]) tot+=a[i];
        ans=min(ans,tot);
    }

    cout<<ans<<nl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("C:/Users/desktop/Downloads/streetlamp_safety_validation_input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}
