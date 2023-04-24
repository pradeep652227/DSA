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
Node* deleteDuplicates(Node* head);

int main()
{
    Node *head = nullptr;
    Node *tail = nullptr;
    insertAtTail(head, tail, 1);
    insertAtTail(head, tail, 1);
    insertAtTail(head, tail, 3);
    insertAtTail(head, tail, 3);
    insertAtTail(head, tail, 3);
    insertAtTail(head, tail, 4);

    cout<<"Initial Linked List- "; printList(head);
    cout<<"After deleting the duplicates- "; head=deleteDuplicates(head);
    printList(head);
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
 
 Node* deleteDuplicates(Node* head) {
        if(head==nullptr || head->next==nullptr)
            return head;
       Node* tempHead=head;
       Node* prev=nullptr;
//1st check how many continuous duplicates are there coz' the problem arises when there're odd no. 
        while(tempHead!=nullptr){
           Node* curr=tempHead;
            if(curr->next==nullptr)
                return head;
           Node* right=curr->next;

            if(curr->getData()==right->getData()){//found duplicates
                Node* rightNext=right->next;
                right->next=nullptr;
                delete right;
                if(rightNext==nullptr){//only 02 duplicates are left- starting 02 or ending 02
                    curr->next=nullptr;
                    delete curr;
                    if(prev==nullptr)//only 02 elements are there in the linked list
                    head=nullptr;
                    else prev->next=nullptr;//otherwise prev->next will point to a deleted address
                    return head;
                }
                else if(curr->getData()==rightNext->getData()){//more than 02 duplicates are there (all continous)
                    curr->next=rightNext;
                    tempHead=curr;
                }
                else {//only 02 duplicates
                    curr->next=nullptr;
                    delete curr;
                    if(prev!=nullptr)//02 duplicates at any place other than start or end
                    prev->next=rightNext;

                    tempHead=rightNext;
                    
                    if(prev==nullptr)//first 02 duplicates
                        head=tempHead;
                }
            }
            else{//if no consecutive duplicates for curr
                prev=tempHead;
                tempHead=tempHead->next;
            }
        }
        return head;
    }