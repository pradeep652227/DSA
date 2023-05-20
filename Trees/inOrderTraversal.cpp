#include <iostream>
#include <stack>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int d):data{d},left{nullptr},right{nullptr} {
    }
};

void inOrderTraversal(Node* root);
void preOrderTraversal(Node* root);
void postOrderTraversal(Node* root);

int main(){
    Node* root=nullptr;
    root=new Node(10);
   root->left=new Node(20);
    root->right=new Node(30);
   root->left->left=new Node(40);
    root->left->right=new Node(50);
    root->right->left=new Node(90);
   root->right->right=new Node(100);

   root->left->left->right=new Node(60);
   root->left->left->right->left=new Node(70);
   root->left->left->right->right=new Node(80);
	
	cout<<"In Order Traversal= ";inOrderTraversal(root);
    cout<<endl;
	cout<<"Pre Order Traversal= ";preOrderTraversal(root);
    cout<<endl;
    cout<<"Post Order Traversal= ";postOrderTraversal(root);
    return 0;
}

void preOrderTraversal(Node* root){
    if(root==nullptr)
        return;
    stack<Node*>st;
    
    while(true){
        while(root!=nullptr){
            cout<<root->data<<" ";//printing the Nth part
            st.push(root);//pusing the Nth part for future Rth part traversing
            root=root->left;//moving to the Lth part
        }
        // if(st.empty())
        //     break;
        // //Lth part is empty so moving to Rth part
        // root=st.top()->right; st.pop();

        //Lth part is empty so moving to Rth part
        root=st.top(); st.pop();
        //Line no.42 se ye check hora ki, at-least 1 node hai tree mein
        if(root->right==nullptr && st.empty())//Lth part bhi null hai Rth part bhi null and stack is empty
            break;
        root=root->right;
    }
    return;
}
/*void preOrderTraversal(Node* root){//N L R
    if(root==nullptr)
        return;

    cout<<root->data<<" ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
    
    return;
}*/

void inOrderTraversal(Node* root){
    if(root==nullptr)
        return;
    stack<Node*>s;
    s.push(root);
    int flag=0;
    //flag=1 matlab upar jao current root->right null hai 
    //flag=0 karo jab root->right mein koi tree hai ya node hai
    while(!s.empty()){

        if(flag==1){//only cover the right part as the left part is covered
           cout<<root->data<<" ";   
           s.pop();
		   
           if(root->right){//going to the right sub-tree
            root=root->right;
            s.push(root);
            flag=0;
           }
           else{//going upward
		   if(s.empty())
				break;
			else
			     root=s.top();
		   }
        }
		else{//flag=0
		while(root->left){
            root=root->left;
            s.push(root);
        }

        cout<<root->data<<" ";//L Part
        s.pop();
			
        if(root->right){//going to the right sub-tree
            root=root->right;
            s.push(root);
        }
        else{//leaf node
		if(s.empty())
			break;
			
            root=s.top();//N in LNR
            cout<<root->data<<" ";
            s.pop();
            if(root->right){//right part of the right sub-tree
                root=root->right;
                s.push(root);
            }
            else{   //going upward after covering the left part
                flag=1;
				if(s.empty())
					break;
                root=s.top();
            }
         }
		}
    }

    return;
}
/*void inOrderTraversal(Node* root){//current part
    if(root==nullptr)
        return;

    inOrderTraversal(root->left);//left part

    if(root->data)//printing the current node (L/N/R)
    cout<<root->data<<" ";
    
    inOrderTraversal(root->right);//right part

    return;
}*/

void postOrderTraversal(Node* root){//N L R
    if(root==nullptr)
        return;
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout<<root->data<<" ";
    
    return;
}