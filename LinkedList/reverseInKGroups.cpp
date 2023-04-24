#include <iostream>

using namespace std;

class Node
{
    int data;
    static int len; // static variable used to store the class information- here, len of the List
public:
    static int getLen();
    Node *next;
    int getData() const { return data; };
    Node(int d);
    ~Node();
};

int Node::len{0}; // initialised the static variable
int Node::getLen()
{
    return len;
}
Node::Node(int d) : data{d}, next{nullptr}
{
    len++;
}
Node::~Node()
{
    len--;
    next = nullptr;
    delete next;
}

void printList(Node *head);
Node *reverseList_in_K_Groups(Node *&head, int k);

int main()
{
    Node *head = nullptr;
    Node *tail = nullptr;

    Node *first = new Node(1);
    Node *sec = new Node(2);
    first->next = sec;
    Node *third = new Node(3);
    sec->next = third;
    Node *fourth = new Node(4);
    third->next = fourth;
    Node *fifth = new Node(5);
    fourth->next = fifth;
    Node *sixth = new Node(6);
    fifth->next = sixth;

    head = first;
    // tail=fifth;
    tail = sixth;
    cout << "Before reversing, the list is " << endl;
    printList(head);
    cout << endl;
    cout << "After reversing, " << endl;
    reverseList_in_K_Groups(head, 4);
    printList(head);

    return 0;
}

void printList(Node *head)
{
    while (head != nullptr)
    {
        cout << head->getData() << " ";
        head = head->next;
    }
    return;
}

Node *reverseList_Recursive(Node *&head, int k, int remNodes)
{
    if (head == nullptr || head->next == nullptr || k == 1 || remNodes < k)
        return head;

    Node *curr = head;
    Node *right = curr->next;
    int count{1};
    while (count < k && right != nullptr)
    {
        Node *rightNext = right->next;
        right->next = curr;
        curr = right;
        right = rightNext;
        count++;
    }
    head->next = reverseList_Recursive(right, k, remNodes - k);
    head = curr;
    return head;
}

Node *nextKthNode(Node *head, int k)
{
    cout << endl
         << "     NextKthNode Function  " << endl;
    int count{1};
    while (count < k && head != nullptr && head->next!=nullptr)
    {
        count++;
        head = head->next;
    }

    return head;
}
Node *reverseList_Iterative(Node *&head, int k)
{

    Node *curr = head;
    Node *right = curr->next;
    if(k>1)
    head=nextKthNode(head,k);//head will only be changed once
    int remNodes{Node::getLen()};
    while (curr != nullptr && right != nullptr && k > 1 && remNodes>=k)
    {
        cout << "head= " << head->getData() << " curr= " << curr->getData() << " right= " << right->getData() << endl;
        Node *tempHead = curr;
        int count{1};
        while (count < k && right != nullptr)
        {
            Node *rightNode = right->next;
            right->next = curr;
            curr = right;
            right = rightNode;
            count++;
        }
        remNodes=remNodes-k;
        curr = right;
        if(remNodes<k)
        tempHead->next=curr;//if we do not want to reverse the next sub-list with size<k
        else
        tempHead->next = nextKthNode(curr,k);

        if (curr != nullptr) right = curr->next;      
        
    }

    return head;
}
Node *reverseList_in_K_Groups(Node *&head, int k)
{
    // int n = Node::getLen();
    // return reverseList_Recursive(head, k, n);

    /*Iterative Solution*/
    return reverseList_Iterative(head, k);
}