#include<bits/stdc++.h>
using namespace std;

#define int        int64_t
#define ff         first
#define ss         second
#define pb         push_back
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a[6] = {4, 8, 15, 16, 23, 42};
    // int q = 4;

    map<int,pair<int,int>> mp;

    for(int i = 0; i < 6; i++){
        for(int j = i+1; j < 6; j++){
            int pr = a[i]*a[j];
            mp[pr] = {a[i],a[j]} ;
        }
    }

    vector<int> ans(6);
    int q,p;

    printf("? 1 2\n");
    fflush(stdout);
    scanf("%d",&p);
    printf("? 2 3\n");
    fflush(stdout);
    scanf("%d",&q);

    pair<int,int> p1 = mp[p];
    pair<int,int> p2 = mp[q];

    auto [m,n] = p1;
    auto [s,r] = p2;

    if(m == s || m == r) {
        ans[1] = m;
        ans[0] = n;
        if(m==s) ans[2] = r;
        else ans[2] = s;
    }
    else {
        ans[1] = n;
        ans[0] = m;
        if(n==s) ans[2] = r;
        else ans[2] = s;
    }
    for(auto &i : ans) cout << i << " ";
    cout << nl;

    printf("? 4 5\n");
    fflush(stdout);
    scanf("%d",&p);
    printf("? 5 6\n");
    fflush(stdout);
    scanf("%d",&q);

    p1 = mp[p];
    p2 = mp[q];

    auto [m1,n1] = p1;
    auto [s1,r1] = p2;

    if(m1 == s1 || m1 == r1) {
        ans[4] = m1;
        ans[3] = n1;
        if(m1==s1) ans[5] = r1;
        else a[5] = s1;
    }
    else {
        ans[4] = n1;
        ans[3] = m1;
        if(n1==s1) ans[5] = r1;
        else ans[5] = s1;
    }
    printf("! ");
    fflush(stdout);
    // for(auto &i : a){
    //     cout << i << " ";
    //     cout.flush();
    // }
    for(int i = 0; i < 6; i++){
        printf("%d ",ans[i]);
        // fflush(stdout);
    }
    // fflush(stdout);
    return 0;
}