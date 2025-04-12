 for(int i = 1; i < n-2; i++){
            if(v[i]!=v[i+1]) ans++;
        }
        cout<<ans+2<<nl;