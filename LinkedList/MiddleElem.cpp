#include <iostream>
using namespace std;
int lenOfList{};
class Node{
  int data;
  static int len;
  public:
  static int getLen();
  Node* next;
  int getData() const {return data;};
  Node(int d);
  ~Node();
};

int Node:: len{0};
int Node:: getLen(){
  return len;
}
Node:: Node(int d):data{d},next{nullptr}{
  lenOfList++;
  len++;
}
Node:: ~Node(){
  lenOfList--;
  len--;
  next=nullptr;
  delete next;
}

void printList(Node* head);
Node* getMiddle(Node* head);

int main() {
  Node* head=nullptr;
  Node* tail=nullptr;
  
  Node* first=new Node(10);
  Node* sec=new Node(20);
  first->next=sec;
  Node* third=new Node(30);
  sec->next=third;
  Node* fourth=new Node(40);
  third->next=fourth;
  Node* fifth=new Node(50);
  fourth->next=fifth;
  Node* sixth=new Node(60);
  fifth->next=sixth;
  

  head=first;
  // tail=fifth;
  tail=sixth;

  printList(head);cout<<endl;
  cout<<"Middle of the list is "; Node* middle=getMiddle(head);
  if(middle==nullptr)
  cout<<" empt node "<<endl;
  else 
  cout<<middle->getData()<<" "<<endl;

  return 0;
}

void printList(Node* head){
  while(head!=nullptr){
    cout<<head->getData()<<" ";
    head=head->next;
  }
  return ;
}
/*//using naive O(N) approach
Node* getMiddle(Node* head){
    if(head==nullptr || head->next==nullptr)
      return head;
    
    int n=Node:: getLen();
    if(n&1){//odd
      int nodeNum{1};
      while(nodeNum!=(n/2+1)){
        head=head->next;
        nodeNum++;
      }
    return head;
    }else {
      int nodeNum{1};
      while(nodeNum!=n/2){
        head=head->next;
        nodeNum++;
      }
      return head;
    }
}*/

//using fast-slow two pointers approach 
Node* getMiddle(Node* head){
  if(head==nullptr || head->next==nullptr){
    return head;
  }
  Node* fast=head->next, *slow=head;
  while(fast!=nullptr){//fast moves 02 steps ahead and 
    fast=fast->next;
    if(fast!=nullptr){
      fast=fast->next;
      slow=slow->next;// slow moves 01 step ahead only when fast has completed 02 steps
    }
  }
  return slow;
}