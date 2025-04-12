#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left = nullptr;
    Node *right = nullptr;
    Node *parent = nullptr;
    Node(data, left, right, parent)
    {
        this.data = data;
    }
};

int main()
{
    Node* root = new Node(1,nullptr,nullptr,nullptr);
    Node* n1 = new Node(2,nullptr,nullptr,root);
    root->left = n1;
    Node* n2 = new Node(3,nullptr,nullptr,root);
    root->right = n2;
    cout<<root->data<<" "<<root->left->data<<" "<<root->left->data;

    return 0;
}