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

void insertAtTail(Node *&head, Node *&tail, int data);
void printList(Node *head);
bool checkPalindrome(Node *head);

int main()
{
    Node *head = nullptr;
    Node *tail = nullptr;
    insertAtTail(head, tail, 1);
    insertAtTail(head, tail, 2);
    insertAtTail(head, tail, 3);
    insertAtTail(head, tail, 3);
    insertAtTail(head, tail, 2);
    insertAtTail(head, tail, 1);

    cout << "Checking whether this list is palindrome or not- ";printList(head);
    cout << endl;
    if (checkPalindrome(head))
        cout << "Yes";
    else
        cout << "No";
    return 0;
}

void insertAtTail(Node *&head, Node *&tail, int data)
{
    Node *newNode = new Node(data);
    if (tail == nullptr)
    {
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    tail = newNode;
    return;
}
void printList(Node *head)
{
    while (head != nullptr)
    {
        cout << head->getData() << " ";
        head = head->next;
    }
    cout<<endl;
    return;
}
/*Space Comlexity- O(N)*/
/*bool checkPalindrome(Node* head){
    int n=Node::getLen();
        if(n<1)
        return true;
        int *arr=new int[n];
        Node* temp=head;
        for(int i=0;i<n && temp!=nullptr;i++){
            arr[i]=temp->getData();
            temp=temp->next;
        }
        int s=0,e=n-1;
        while(s<e){
            if(arr[s]!=arr[e])
                return false;
            s++;e--;
        }

        return true;
}
*/

Node* reverseList(Node* head){
    if(head==nullptr)
        return head;
    Node* curr=head;
    Node* right=curr->next;
    
    while (right != nullptr)
    {
        Node *rightNext = right->next;
        right->next = curr;
        curr = right;
        right = rightNext;
    } // curr will be at the last node or the head of this subList
    head->next=nullptr;
    head=curr;
    return head;
}
/*Space Complexity O(1)*/
bool checkPalindrome(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return true;
    // 1st- find middle
    Node *middle{nullptr};
    Node *slow = head, *fast = head->next;
    while (fast != nullptr)
    {
        fast = fast->next;
        if (fast != nullptr)
        {
            fast = fast->next;
            slow = slow->next;
        }
    }
    middle = slow;
    cout<<endl<<"Middle is "<<middle->getData()<<endl;

    // Step2nd- reverse the list after middle
    Node *head2 = reverseList(middle->next);
    middle->next = head2;
    cout<<endl<<"Reversed List after middle- "; printList(head);
    // Step3rd- traverse the linked list with two pointers head1 and head2 of two sublists on either side of middle
    Node* head1=head;
    cout<<"Head1= "<<head1->getData()<<"Head2= "<<head2->getData()<<endl;
    while(head2!=nullptr){
        if(head1->getData()!=head2->getData())
        return false;
        head1=head1->next;
        head2=head2->next;
    }
    return true;//ll is palindrome
}
