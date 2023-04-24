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
Node* insertAtTail(Node* head,Node* tail,int data);
//void insertAtTail(Node* &head,Node* &tail,int data);
void printLinkedList(Node* head);
int lenLList(Node* head);
void insertAtPosi(Node* &head,Node* &tail,int posi,int data);
void deleteNode(Node* &head,Node* &tail,int data);
void reversePrintLinkedList(Node* head);
int main(){

//	Node* head=new Node(10);
	Node* head=nullptr;
	Node* tail=nullptr;
//	insertAtHead(head,tail,10);
//	insertAtHead(head,tail,20);
//	insertAtHead(head,tail,30);
//	insertAtHead(head,tail,40);
//	insertAtHead(head,tail,50);
//	cout<<"Tail= "<<tail->getData()<<endl;

	tail=insertAtTail(head,tail,9);
	head=tail;
//	cout<<"Tail->getData() "<<tail->getData()<<endl;
//	cout<<"Tail->next= "<<tail->next->getData()<<endl;
	tail=insertAtTail(head,tail,8);
	tail=insertAtTail(head,tail,7);
	tail=insertAtTail(head,tail,6);
	printLinkedList(head);
	cout<<"Tail= "<<tail->getData()<<endl;
	
//	cout<<"At which position between 1 to "<<lenLList(head)<<"to add data "<<endl;
//	int posi{};cin>>posi;
//	cout<<"Data to add? "; int data{};cin>>data;
//	insertAtPosi(head,tail,posi,data);
//	cout<<"After inserting, "<<endl;
//	printLinkedList(head);
	
//	cout<<"Which node to delete, enter value "; int delNodeData{}; cin>>delNodeData;
//	deleteNode(head,tail,delNodeData);
//	cout<<"After deleting, "<<endl;
//	printLinkedList(head);
//	cout<<" Tail= "<<tail->getData()<<endl;
	return 0;
}

void insertAtHead(Node* &head, Node* &tail,int data){
	Node* newNode=new Node(data);
	newNode->next=head;
	if(head==nullptr)//first node create karne jaare hai
		tail=newNode;
	head=newNode;// Now head is the newNode
	return ;
}
Node* insertAtTail(Node* funcHead,Node* funcTail,int data){
	Node* newNode=new Node(data);
	if(funcTail==nullptr){
//		funcTail=newNode;
//		funcHead=newNode;
		return newNode;
	}
	funcTail->next=newNode;
//	funcTail=newNode;
	return newNode;
}
//void insertAtTail(Node* &head,Node* &tail,int data){
//	Node* newNode=new Node(data);
//	if(tail==nullptr){
//		tail=newNode;
//		head=newNode;
//		return;
//	}
//	tail->next=newNode;
//	tail=newNode;
//	return;
//}
int lenLList(Node* head){
	int len{0};
	while(head!=nullptr){
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
			head=newNode;
			tail=newNode;
			return;
		}
		
		if(posi==1){// if at head
			newNode->next=head;
			head=newNode;
			return ;
		}
		if(posi==len){// if at tail
			tail->next=newNode;
			tail=newNode;
			return;
		}
		int nodeNum{2};
		Node* prevNode{head};
		while(nodeNum<len){// in between head and tail
			if(nodeNum==posi){
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
		
	if(head->getData()==data){
		Node* temp=head->next;
		head->next=nullptr;
		delete head;
		head=temp;
		return ;
	}
	int len=lenLList(head);
	int nodeNum{2};
	Node* prevNode=head;
	while(nodeNum<=len){
		Node* currNode=prevNode->next;
		if(currNode->getData()==data){
			prevNode->next=currNode->next;
			currNode->next=nullptr;
			delete currNode;
			if(nodeNum==len)
				tail=prevNode;
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