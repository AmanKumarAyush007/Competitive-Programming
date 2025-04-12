//Binary Search Tree Implementation

#include <bits/stdc++.h>
using namespace std;

class node{
public:
    int data;
    node* left = nullptr;
    node* right = nullptr;
    int size;
    node(int val){
        this->data = val;   //without this program also runs
    }
};

class bst{
    
    // int val;
    private:
    node* root = nullptr;
    node* insert(node* root, int val){
        node* ni = new node(val);
        if(root == nullptr) return ni;
        if(root->data == val) return root;

    }
    public:
    void insert(int data){
        root = insert(node* root,data);
    }
};

int main(){
    node* n1 = new node(5);
    node* n2 = new node(6);
    node* n3 = new node(7); 
    n1->right = n3;
    n1->left = n2;

    cout << n1->data;
    cout << n1->right->data;
    cout << n1->left->data;





    

    

    return 0;
}

