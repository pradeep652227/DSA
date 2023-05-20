#include <iostream>
#include <climits>

using namespace std;

class Node{
public:
    int data;   
    Node* next;
    Node(int d):data{d},next{nullptr}{
    }
    ~Node(){
        this->next=nullptr;
        delete next;
    }
};

class Stack{
    Node* top;
    int currSize;
public:
    Stack();
    void push(int d);
    void pop();
    int peek() const;
    int size() const;
    bool empty() const;

    void display() const;
};

int main(){
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    s.display();

    s.pop();
    s.pop();    
    cout<<endl;

    s.display();
    cout<<endl;

    cout<<s.peek()<<endl;
    cout<<s.size()<<endl;

    return 0;
}

Stack:: Stack():top{nullptr}, currSize{0}{
}

void Stack:: push(int d){
    Node* newNode=new Node(d);
    if(!newNode){
        cout<<"Stack Overflow"<<endl;
        exit(-1);
    }
    currSize++;
    Node* prevNode=top;
    top=newNode;
    top->next=prevNode;
    return;
}

void Stack::pop(){

    if(top==nullptr)
        cout<<"Stack Underflow"<<endl;
    else{
    Node* nextNode=top->next;
    delete top;
    top=nextNode;
    currSize--;
    }
    return;
}

int Stack::peek() const{
    if(top==nullptr){
        cout<<"Stack is empty, no top element."<<endl;
        return INT_MIN;
    }
    return top->data;
}

int Stack::size() const{
    return currSize;
}

bool Stack::empty() const{
    if(top==nullptr)
        return true;
    else
    return false;
}

void Stack::display() const{
    Node* temp=top;
    while(temp!=nullptr){
        cout<<temp->data<<endl;
        temp=temp->next;
    }
    return;
}