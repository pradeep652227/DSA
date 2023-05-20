#include <iostream>
#include <queue>
using namespace std;

class Tree
{
public:
    int data;
    Tree *left;
    Tree *right;

    Tree(int d) : data{d}, left{nullptr}, right{nullptr}
    {
    }
};
typedef Tree Node;

Tree *buildTree(int data);
void printTree(Node *root);

int main()
{
    int data{};
    cout << "Enter the root node data ";
    cin >> data;
    Tree *root = buildTree(data);
    cout << endl
         << "Tree built by your values is " << endl;
    printTree(root);

    return 0;
}
void printTree(Node *root)
{
    if (root == nullptr)
        return;
    queue<Node *> q;
    q.push(root);
    q.push(nullptr);
    while (!q.empty())
    {
        Node *root = q.front();
        q.pop();
        if (root == nullptr)
        {
            cout << endl;
            if(q.empty())
                return; 
            else
            q.push(nullptr); // new level created
        }
        else
        {
            cout << root->data << " ";
            Node *leftNode = root->left, *rightNode = root->right;
            if (leftNode != nullptr)
                q.push(leftNode);
            if (rightNode != nullptr)
                q.push(rightNode);
        }
        
    }
    return;
}

Node *buildTree(int data)
{
    if (data == -1)
        return nullptr;
    queue<Node *> q;
    Node *root = new Node(data);
    q.push(root);
    while (!q.empty())
    {
        Node *root = q.front();
        int d = root->data;
        q.pop();
        cout << "Enter data for the left child of " << d << "= ";
        int lData{};
        cin >> lData;
        if (lData != -1)
        {
            root->left = new Node(lData);
            q.push(root->left);
        }
        cout << "Enter data for right child of " << d << "= ";
        int rData{};
        cin >> rData;
        if (rData != -1)
        {
            root->right = new Node(rData);
            q.push(root->right);
        }
    }
    return root;
}

/*Tree* buildTree(int data){
    if(data==-1)
        return nullptr;

    Tree* root=new Tree(data);
    cout<<"Enter data for left child of "<<data<<"= ";
    int leftData; cin>>leftData;
    root->left=buildTree(leftData);

    cout<<"Enter data for right child of "<<data<<"= ";
    int rightData; cin>>rightData;
    root->right=buildTree(rightData);

    return root;
}*/