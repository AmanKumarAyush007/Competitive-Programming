#include<bits/stdc++.h>
using namespace std;



void solve(){

    string myText;

    // Read from the text file
    ifstream MyReadFile;

    MyReadFile.open("tey.txt");



    // Use a while loop together with the getline() function to read the file line by line
    int i = 0;
    while (getline (MyReadFile, myText)) {
      // Output the text from the file
      cout<< i << " -> " << myText << endl;
      i++;
    }

    cout << MyReadFile.is_open() <<  endl;


    // Close the file
    MyReadFile.close(); 

    cout << MyReadFile.is_open() <<  endl;

    
    cout << endl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}