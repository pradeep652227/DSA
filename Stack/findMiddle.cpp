#include <iostream>
#include "stack.cpp"
#include <stack>

using namespace std;
void printStack(Stack s){
    if(s.empty())
		return;
	int removedTop=s.peek();
	cout<<removedTop<<endl;
	s.pop();
	printStack(s);
	s.push(removedTop);
	return;
}

void print(stack<int> s){
	while(!s.empty()){
		cout<<s.top()<<endl;
		s.pop();
	}	
	return;
}

int findMiddle(Stack& s,int size);
int main(){
	stack<int> s;
	s.push(10);
	s.push(20);
	s.push(30);
	print(s);
	cout<<"Top After printing function= "<<s.top()<<endl;
/*    Stack s(7);
    s.push(1);
    s.push(2);
    // s.push(3);
    // s.push(4);
    // s.push(5);
    // s.push(6);
    // s.push(7);
    printStack(s);
    cout<<" TOp= "<<s.peek()<<endl;
//   cout<<"The middle element of the above Stack is :- ";
//   cout<<" \""<<findMiddle(s,s.size())<<" \""<<endl;
//   cout<<endl<<endl;
//
//   printStack(s);

*/
    return 0;
}

int mid_recursive(Stack& s, int size,int midIdx){
        if(size==midIdx+1)
            return s.peek();
       int removedTop= s.peek();
       cout<<"Top is at "<<removedTop<<" ";
       s.pop();//removing the top
       cout<<", Top after pop()= "<<s.peek()<<endl;
       int midElem=mid_recursive(s,size-1,midIdx);
       cout<<" Before adding, Top= "<<s.peek()<<" ";
       s.push(removedTop);//adding back the top
       cout<<", Adding removedTop, Top= "<<s.peek()<<" ";
       cout<<endl;
       return midElem;
}

int findMiddle(Stack& s,int size){
    int midIdx{size/2};
    if(size%2==0)//size is even
        midIdx=midIdx-1;
    return mid_recursive(s,size,midIdx);
}
