#include <iostream>
#include <queue>

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

int main(){
    Node* root=nullptr;
    root=new Node(10);
    root->left=new Node(20);
    root->right=new Node(30);
    root->left->left=new Node(40);
    root->left->right=new Node(50);
    root->right->left=new Node(60);
    root->right->right=new Node(70);
	
	cout<<"height of the tree is "<<heightOfATree(root)<<endl;

    return 0;
}

int heightOfATree(Node* root){
    if(root==nullptr)
        return 0;
    int lH=heightOfATree(root->left);
    int rH=heightOfATree(root->right);

    return 1+ max(lH,rH);
}

/*int heightOfATree(Node* root){
    if(root==nullptr)
            return 0;
        queue<Node*>q;
        q.push(root);
        q.push(nullptr);
        int l{-1};
        while(!q.empty()){
            Node* temp=q.front();
            q.pop();
            if(temp==nullptr){
                l++;
                if(!q.empty())
                    q.push(nullptr);
                else 
                return l+1;
            }
            else{
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
        }
    return l+1;
}*/