#include <iostream>

using namespace std;

int lenOfList{};
class Node{
	int data;
	int nodeNum;
public:
	Node *prev, *next;
	Node(int data=0):data{data},prev{nullptr},next{nullptr}, nodeNum{0}{
		lenOfList++; nodeNum=lenOfList;
	}
	~Node(){
		cout<<"Deleting node with data= "<<getData()<<" and nodeNumber= "<<nodeNum<<endl;
		lenOfList--;
		delete prev;
		delete next;
	}
	int getData()const{ 
		return data;
	}
};
void printList(Node* head);
void reversePrint(Node* temp);
void insertAtHead(Node* &head,Node* &tail,int data);
void insertAtTail(Node* &head,Node* &tail,int data);
void insertAtPosi(Node* &head,Node* &tail,int &posi,int &data);
void delNode(Node* &head,Node* &tail,int data);

int main(){
	Node* head=nullptr;
	Node* tail=nullptr;
	insertAtHead(head,tail,10);
	insertAtHead(head,tail,20);
	insertAtHead(head,tail,30);
	insertAtHead(head,tail,40);
//	reversePrint(tail); cout<<"Tail= "<<tail->getData()<<endl;
//	
//	insertAtTail(head,tail,1);
//	insertAtTail(head,tail,2);
//	insertAtTail(head,tail,3);
//	insertAtTail(head,tail,4);
//	printList(head); cout<<"Head= "<<head->getData()<<" Tail= "<<tail->getData()<<endl;
//	
//	cout<<"At which position between 1 to "<<lenOfList<<" ,we need to add data ";int posi{};cin>>posi;
//	cout<<"Data to add? "; int data{};cin>>data;
//	insertAtPosi(head,tail,posi,data);
//	cout<<"After inserting, "<<endl;
//	printList(head);
//	
//	cout<<"Which node to delete, enter data "; int dataToDel{};cin>>dataToDel;
//	delNode(head,tail,dataToDel);
//	cout<<"After deleting, "<<endl;
	printList(head);
	return 0;
}

void printList(Node* head){
	while(head!=nullptr){
		cout<<head->getData()<<" ";
		head=head->next;
	}
	return;
}
void reversePrint(Node* temp){
	while(temp!=nullptr){
		cout<<temp->getData()<<" ";
		temp=temp->prev;
	}
	return;
}
void insertAtHead(Node* &head,Node* &tail,int data){
	
	Node* newNode=new Node(data);
	if(head==nullptr){
		head=tail=newNode;
		return;
	}
	newNode->next=head;
	head->prev=newNode;
	head=newNode;
	
	return;
}

void insertAtTail(Node* &head,Node* &tail,int data){
	
	Node* newNode=new Node(data);
	if(tail==nullptr){
		head=tail=newNode;
		return;
	}
	tail->next=newNode;
	newNode->prev=tail;
	tail=newNode;
	return;
}

void insertAtPosi(Node* &head,Node* &tail,int &posi,int &data){
	if(posi>lenOfList || posi<1)
		return ;
	Node* newNode=new Node(data);
	if(head==nullptr){//empty LL
		head=tail=newNode;
		return;
	}
	if(posi==1){// at head
		newNode->next=head;
		head->prev=newNode;
		head=newNode;
		return;
	}
	if(posi==lenOfList){//at tail
		tail->next=newNode;
		newNode->prev=tail;
		tail=newNode;
		return;
	}
	//between head and tail
	Node* prevNode=head;
	for(int i=2;i<lenOfList;i++){
		if(i==posi){
			Node* rightNode=prevNode->next;
			prevNode->next=newNode;
			newNode->prev=prevNode;
			newNode->next=rightNode;
			rightNode->prev=newNode;
			return;
		}
		prevNode=prevNode->next;
	}
	return;
}

void delNode(Node* &head,Node* &tail,int data){
	if(head==nullptr){
		cout<<"Cannot delete node as the List is empty"<<endl;
		return;
	}
	if(head->getData()==data){// if head is to be deleted
		Node* rightNode=head->next;
		head->next=nullptr;
		rightNode->prev=nullptr;
		delete head;
		head=rightNode;
		return;
	}
	Node* prevNode=head;
	for(int i=2;i<=lenOfList;i++){
		Node* currNode=prevNode->next;
		if(currNode->getData()==data){
			Node* leftNode=prevNode;
			if(i==lenOfList){// if tail is to be deleted
				leftNode->next=nullptr,currNode->prev=nullptr;
				delete currNode;tail=prevNode; 
				return;
			}
			Node* rightNode=currNode->next;
			currNode->next=nullptr; currNode->prev=nullptr;
			delete currNode;
			leftNode->next=rightNode;
			rightNode->prev=leftNode;
			return;
		}
		prevNode=currNode;// =prevNode->next
	}
	cout<<"No such data exists"<<endl;
	return; 
}