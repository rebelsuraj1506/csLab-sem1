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
void allTraversal(Node* root)
{
    vector<string>pre;
    vector<string>post;
    vector<string>in;
    stack<pair<Node*,int>>s;
    s.push(make_pair(root,1));
    while(!s.empty())
    {
        pair<Node*,int>p=s.top();
        if(p.second==1)
        {
            s.top().second++;
            pre.push_back(p.first->data);
            if(p.first->left){
                s.push(make_pair(p.first->left,1));
            }
        }
        else if(p.second==2){
            s.top().second++;
            in.push_back(p.first->data);
            if(p.first->right)
            {
                s.push(make_pair(p.first->right,1));
            }
        }
        else{
            post.push_back(p.first->data);
            s.pop();
        }
    }
    cout<<"Preorder Traversal: ";
    for(int i=0;i<pre.size();i++)
    {
        cout<<pre[i]<<" ";
    }
        cout<<endl;
    cout<<"Postorder Traversal: ";
    for(int i=0;i<post.size();i++)
    {
        cout<<post[i]<<" ";
    }
    cout<<endl;
    cout<<"Inorder Traversal: ";
    for(int i=0;i<in.size();i++)
    {
        cout<<in[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    struct Node *root=new Node("A");
    root->left = new Node("B");
    root->right = new Node("C");
    root->left->left = new Node("D");
    root->left->right = new Node("E");
    root->right->left = new Node("F");
    root->right->right = new Node("G");
    allTraversal(root);
    
}