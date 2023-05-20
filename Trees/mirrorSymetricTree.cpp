#include <iostream>

using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int d=0):data{d},left{nullptr},right{nullptr} {
    }
};

bool isSymmetric(Node* root);

int main(){
    Node* root=nullptr;
    root=new Node(10);
    root->left=new Node(20);
    root->right=new Node(20);
    root->left->left=new Node(30);
    root->left->right=new Node(40);
    root->right->left=new Node(40);
    root->right->right=new Node(30);
	
	cout<<"Tree is Symmetric or not? "<<isSymmetric(root)<<endl;

    return 0;
}

bool isSameHalves(Node *p, Node *q)
{
    if (p == nullptr || q == nullptr)
    {
        if (q == nullptr && p == nullptr)
            return true;
        else
            return false;
    }

    int ans1 = isSameHalves(p->left, q->right);
    int ans2 = isSameHalves(p->right, q->left);
    if (ans1 & ans2)
    { // pLR and qLR are same
        int pData = p->data;
        int qData = q->data;
        if (pData != qData)
            return false;
        else
            return true;
    }
    else
        return false;
}
bool isSymmetric(Node *root)
{
    if (root == nullptr)
        return false;

    Node* leftNode = root->left;
    Node* rightNode = root->right;
    if(leftNode==nullptr || rightNode==nullptr){
        if(rightNode==nullptr && leftNode==nullptr)
            return true;
        else 
            return false;
    }

    if (leftNode->data != rightNode->data)
        return false;
    return isSameHalves(leftNode, rightNode);
}