#include <iostream>

using namespace std;

class Node{
	int data;
public:
	Node *next;
	Node();
	Node(int data);
	~Node();
	int getData()const;
};

Node::Node(int data):data{data},next{NULL}{
}

Node::Node():Node(0){
}
Node::~Node(){
	cout<<"Destructor Called for data= "<<data<<" with object &= "<<this<<endl;
	delete next;
}

int Node:: getData()const{
	return data;
}

void insertAtHead(Node* &head,Node* &tail,int data);
void insertAtTail(Node* &head,Node* &tail,int data);
void printLinkedList(Node* head);
int lenLList(Node* head);
void insertAtPosi(Node* &head,Node* &tail,int posi,int data);
void deleteNode(Node* &head,Node* &tail,int data);
void reversePrintLinkedList(Node* head);
int main(){

	Node* head=nullptr;
	Node* tail=nullptr;
	insertAtTail(head,tail,10);
	cout<<"Len= "<<lenLList(head)<<" head= "<<head<<" head->next= "<<head->next<<" tail->next "<<tail->next<<endl;
	insertAtTail(head,tail,20);
	insertAtHead(head,tail,30);
	insertAtHead(head,tail,40);
	printLinkedList(head);
	
//	cout<<"At which position between 1 to "<<lenLList(head)<<"to add data "<<endl;
//	int posi{};cin>>posi;
//	cout<<"Data to add? "; int data{};cin>>data;
//	insertAtPosi(head,tail,posi,data);
//	cout<<"After inserting, "<<endl;
//	printLinkedList(head);

	cout<<"Which node to delete, enter value "; int delNodeData{}; cin>>delNodeData;
	deleteNode(head,tail,delNodeData);
	cout<<"After deleting, "<<endl;
	printLinkedList(head);
	cout<<" Tail= "<<tail->getData()<<" and tail->next= "<<(tail->next)->getData()<<endl;
	
	return 0;
}

void insertAtHead(Node* &head, Node* &tail,int data){
	Node* newNode=new Node(data);
	newNode->next=head;
	if(head==nullptr)//first node create karne jaare hai
	{	tail=newNode; tail->next=head;}
	head=newNode;// Now head is the newNode
	tail->next=head;// pointing to the newAddress of head
	return ;
}
void insertAtTail(Node* &head,Node* &tail,int data){
	Node* newNode=new Node(data);
	if(tail==nullptr){
		tail=newNode;
		head=newNode;
		tail->next=head;
		return;
	}
	tail->next=newNode;
	tail=newNode;
	tail->next=head;//new Tail, and newNode->next= nullptr so tail->next=nullptr
	return;
}
int lenLList(Node* head){

	if(head==nullptr)
		return 0;
//	if(head->next==nullptr)
//	{ cout<<"head->next= null"<<endl;	return 1; }
	Node* origHead=head;
	head=head->next;
	int len{1};
	while(head!=origHead){
		len++;
		head=head->next;
	}
	return len;
}
void insertAtPosi(Node* &head,Node* &tail,int posi,int data){//referencing is necessary, what if posi=
	
		int len=lenLList(head);
		if(posi>len || posi<1)
			return ;
			
		Node* newNode=new Node(data);
		if(head==nullptr)//LL is empty
		{
			insertAtHead(head,tail,data);
		}
		
		if(posi==1){// if at head
			insertAtHead(head,tail,data);
			return;
		}
		if(posi==len){// if at tail
			insertAtTail(head,tail,data);
			return;
		}
		int nodeNum{2};
		Node* prevNode{head};
		while(nodeNum<len){// in between head and tail
			if(nodeNum==posi){
		// left node= prevNode, rightNode= prevNode->next and currNode(middleNode)=newNode
				Node* rightNode{prevNode->next};
				prevNode->next=newNode;
				newNode->next=rightNode;
				return ;
			}
			prevNode=prevNode->next;
			nodeNum++;
		}
	return ;
}
void deleteNode(Node* &head,Node* &tail,int data){
	if(head==nullptr)
		return ;
	if(head->next==head){// only 1 node
		head->next=nullptr;
	}
	if(head->getData()==data){// 1st node to delete
		Node* temp=head->next;
		head->next=nullptr;
		delete head;
		head=temp;
		tail->next=head; // pointing to the newAddress pointed by new head
		return ;
	}
	int len=lenLList(head);
	int nodeNum{2};
	Node* prevNode=head;
	while(nodeNum<=len){//(head,tail]
		Node* currNode=prevNode->next;
		if(currNode->getData()==data){
			prevNode->next=currNode->next;
			currNode->next=nullptr;
			delete currNode;
			if(nodeNum==len)
			{ tail=prevNode; tail->next=head; }
			return;
		}
		prevNode=currNode;
//		prevNode=prevNode->next;
		nodeNum++;
	}
	//checking if tail is to be deleted
//	if(prevNode->getData()==data){
//		prevNode->next=nullptr;
//		delete tail;
//		tail=prevNode;
//	}
	return ;
}
void printLinkedList(Node* head){
	int nodeNum{1};
	int len=lenLList(head);
	while(nodeNum<=len){
		cout<<head->getData()<<" ";
		if(nodeNum!=len)
		head=head->next;
		nodeNum++;
	}

	return ;
}