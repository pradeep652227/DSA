#include <iostream>
#include <queue>

using namespace std;

class Tree{
public:
    int data;
    Tree* left;
    Tree* right;

    Tree(int d):data{d},left{nullptr},right{nullptr} {
    }
};

Tree* buildTree(int data);
void levOrderTraversal(Tree* root);

int main(){
    int data{};
    cout<<"Enter the root node data "; cin>>data;
    Tree* root=buildTree(data);
    cout<<"Level Order Traversal is ";levOrderTraversal(root);
    return 0;
}

Tree* buildTree(int data){
    if(data==-1)
        return nullptr;

    Tree* root=new Tree(data);
    cout<<"Enter data for left child ";
    int leftData; cin>>leftData;
    root->left=buildTree(leftData);

    cout<<"Enter data for right child ";
    int rightData; cin>>rightData;
    root->right=buildTree(rightData);

    return root;
}

void levOrderTraversal(Tree* root){
    if(root==nullptr)
        return;
    queue<Tree *>q;
    q.push(root);
    q.push(nullptr);
    while(!q.empty()){
        Tree* temp=q.front();
        q.pop();
        if(temp==nullptr){
            cout<<endl;
            if(!q.empty())
                q.push(nullptr);
            else 
                return;
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
    }
}