#include<bits/stdc++.h>
using namespace std;
struct Node{
    string data;
    struct Node  *left,*right;
    Node(string data)
    {
        this->data=data;
        left=right=NULL;
    }
};
int diameter(Node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    if(root->left==NULL && root->right==NULL)
    return 1;
    else if(root->left==NULL)
    {
        return 1+diameter(root->right); 
    }
    else if(root->right==NULL)
    {
        return 1+diameter(root->left);
    }
    else{
        return max((1+diameter(root->right)),(1+diameter(root->left)));
    }
}
int main()
{
    struct Node *root=new Node("A");
    root->left = new Node("B");
    root->right = new Node("C");
    root->left->left = new Node("D");
    root->left->left->left = new Node("H");
    root->left->left->left->right = new Node("I");
    root->left->right = new Node("E");
    root->right->left = new Node("F");
    root->right->right = new Node("G");
    cout<<diameter(root->left)+diameter(root->right);
    cout<<endl;
}