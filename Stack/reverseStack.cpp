#include <iostream>
#include <stack>

using namespace std;
void insertAtBottom(stack<int>& s,int target);
void reverseStack(stack<int>& s);
void print(stack<int> s){
    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }
}

int main(){
    stack<int>s;
    s.push(1);
    s.push(2);
    s.push(3);
    cout<<"Before reversing stack is:- "<<endl;
    print(s);
    cout<<endl<<"After reversing, :-"<<endl;
    reverseStack(s);
    print(s);
    return 0;
}

void insertAtBottom(stack<int>& s,int target){
    //base case
        if(s.empty()){
            s.push(target);//inserted target at bottom
            return;
        }
    //Code
    int topElem=s.top();
    s.pop();
    insertAtBottom(s,target);
    s.push(topElem);
    return;
}

void reverseStack(stack<int>& s){
    //base case
    if(s.empty())
        return;

    int topElem=s.top();//nth element
    s.pop();
    reverseStack(s);//n-1 elements reverse karke dega
    insertAtBottom(s,topElem);//reversing the whole stack
    return;
}