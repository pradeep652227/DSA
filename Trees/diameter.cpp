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

int heightOfATree(Node* root);
int diameterOfATree(Node* root);

int main(){
    Node* root=nullptr;
    root=new Node(10);
    root->left=new Node(20);
    root->right=new Node(30);
    root->left->left=new Node(40);
    root->left->right=new Node(50);
    root->right->left=new Node(60);
    root->right->right=new Node(70);
	
	cout<<"Diameter of the tree is "<<diameterOfATree(root)<<endl;

    return 0;
}

int heightOfATree(Node* root){
    if(root==nullptr)
        return 0;
    int lH=heightOfATree(root->left);
    int rH=heightOfATree(root->right);

    return 1+ max(lH,rH);
}

int diameter(Node* root,int& diamMax){
        if(root==nullptr)
        return 0;
    int h1=diameter(root->left,diamMax);
    int h2=diameter(root->right,diamMax);
    if(root->left || root->right){
        int tempDiam=h1+h2;
        diamMax=max(tempDiam,diamMax);
    }

    return max(h1,h2)+1;
}
int diameterOfATree(Node* root){
    int diamMax{0};
    if(root->left==nullptr && root->right==nullptr)
        return 0;//by edges
    diameter(root,diamMax);
    return diamMax;
}