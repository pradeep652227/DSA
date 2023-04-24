#include <iostream>

using namespace std;

int lenOfList{};
class Node{
	int data;
public:
	Node* next;
	Node(int data=0);
	~Node();
	int getData() const;
};
Node:: Node(int data):data{data},next{nullptr}{
	lenOfList++;
}
Node:: ~Node(){
	lenOfList--;
	next=nullptr;
	delete next;
}
int Node:: getData() const{
	return data;
}
void insertAtTail(Node* &head,Node* &tail,int data);
void printList(Node* head);
void revListByRecurrsion(Node* currNode,Node* rightNode);
void reverseLinkedList(Node* &head);
void reversePrint(Node *tail);

int main(){
	int const a=5;
	Node* head=nullptr;
	Node* tail=nullptr;
	insertAtTail(head,tail,10);
	insertAtTail(head,tail,20);
	insertAtTail(head,tail,30);
	insertAtTail(head,tail,40);
	cout<<"Before reversing, Linked List is- ";printList(head);
	cout<<endl;
	
	cout<<"After reversing, It is- "; 
	revListByRecurrsion(nullptr,head);
//	reverseLinkedList(head); 
	Node* tempHead=head;
	head=tail;
	tail=tempHead;
	printList(head);
//	reversePrint(tail);
	
	return 0;
}

void insertAtTail(Node* &head,Node* &tail,int data){
	Node* newNode=new Node(data);
	if(tail==nullptr){
		head=tail=newNode;
		return;
	}
	tail->next=newNode;
	tail=newNode;
	return; 
}

void printList(Node* head){
	while(head!=nullptr){
		cout<<head->getData()<<" ";
		head=head->next;
	}
	return;
}
void revListByRecurrsion(Node* currNode,Node* rightNode){
	
	if(rightNode==nullptr)
		return;
		
	Node* rightNextNode=rightNode->next;
	rightNode->next=currNode;
	currNode=rightNode;rightNode=rightNextNode;
	
	revListByRecurrsion(currNode,rightNode);
}
/*
void reverseLinkedList(Node* &head){
	if(head==nullptr)
		return;

	Node* currNode=head;
	Node* rightNode=currNode->next;
	if(lenOfList==1){
		return; 
	}
	while(rightNode!=nullptr){
		Node* rightNodeNext=rightNode->next;
//		cout<<"CurrNode= "<<currNode->getData()
//			<<"rightNode= "<<rightNode->getData();
		rightNode->next=currNode;
		currNode=rightNode;
		rightNode=rightNodeNext;
//		cout<<"CurrNode->next->data "<<(currNode->next->)getData()
	}
	head->next=nullptr;
	return ;

}
*/

void reversePrint(Node* tail){
	while(tail!=nullptr){
		cout<<tail->getData()<<" ";
		tail=tail->next;
	}
	return ;
}