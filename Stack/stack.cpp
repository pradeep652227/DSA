#include <iostream>
#include <climits>
#include "stack.h"

using namespace std;

//cout<<"Hello"<<endl;

Stack:: Stack(int size):arr{nullptr},n{0},top{-1}{
	cout<<"Stack is created with size= "<<size<<endl;
	n=size;
    arr=new int[size];
}

void Stack:: push(int d){
	 top++;//incrementing to the current index
     if(top==n){
        cerr<<"Stack Overflow"<<endl;
        return;
    }
    arr[top]=d;
    return;
}

void Stack:: pop(){
    if(top==-1){
        cerr<<"Stack Underflow"<<endl;
        return;
    }
    int *elemToDel=arr+top;
    // cout<<*elemToDel<<" Is deleted "<<endl;
    delete elemToDel;
    top--;
}

bool Stack::empty() const{
    if(top==-1)
        return true;
    else 
        return false;
}
int Stack::size() const{
    return top+1;//no. of curr elements
}

int Stack::peek() const{
    if(top!=-1)
		return arr[top];
	else {
        cout<<"No elems are present in the Stack"<<endl;
        return INT_MIN;
    }
		
}

Stack::~Stack(){
    cout<<"Stack is now deleted"<<endl;
    top=-1;
    delete [] arr;
}
