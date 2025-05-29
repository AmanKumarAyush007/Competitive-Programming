#include<bits/stdc++.h>
using namespace std;

struct node{
    node* links[26];
    bool wordEnds = false;

    bool containsKey(char c){
        return (links[c - 'a'] != NULL);
    }

    void put(char c, node* Node){
        links[c - 'a'] = Node;
    }

    node* get(char c){
        return links[c - 'a'];
    }

    void end(){
        wordEnds = true;
    }
};

class Trie{
    private: 
    node* root;


    public:
    int get_size = 0;

    Trie(){
        root = new node();
    }

    void insert(string word) {

        for(int i = 0; i < word.length(); i++){
            word[i] = tolower(word[i]);
        }

        node* curr = root;

        for(int i = 0; i < word.length(); i++){
            if(!(curr -> containsKey(word[i]))){
                curr -> put(word[i],new node());
            }
            curr = curr -> get(word[i]);
        }

        curr -> end();

        get_size++;
        
    }

    bool search(string word) {

        for(int i = 0; i < word.length(); i++){
            word[i] = tolower(word[i]);
        }

        node* curr = root;
        for(int i = 0; i < word.length(); i++){
            if(!(curr -> containsKey(word[i]))) return false;
            curr = curr -> get(word[i]);
        }

        return (curr -> wordEnds);    
    }

};


int main(){

    Trie dictionary;
    ifstream words("words.txt");
    
    string s;

    // inserting all the word into tries
    while(getline(words,s)){
        if(s.size()) dictionary.insert(s);
    }

    int n;
    cin >> n;

    while(n--){
        string s;
        cin >> s;

        if(dictionary.search(s)) cout << "Found\n";
        else cout << "Not Found\n";
    }

    return 0;
}