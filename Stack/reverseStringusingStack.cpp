#include <iostream>
#include <cstring>
#include <climits>
using namespace std;

class Stack_string{
    char* str;
    int n;
    int top;
public:
    Stack_string(int size);
    void push(char ch);
    void pop();
    bool empty() const;
    int size() const;
    char peek() const;

    ~Stack_string();
};
char* reverse(char* str,int len){
     if(len==1)
        return str;
    Stack_string s(len);
    for(int i=0;i<len;i++){
        s.push(str[i]);
    }
    int idx=0;
    while(!s.empty()){
        
        str[idx]=s.peek();
        s.pop();
        idx++;
    }
    return str;
}
int main()
{   Stack_string s(7);
    char str[]="Pradeep";
    cout<<"String = "<<str<<endl;
    int len=strlen(str);
    reverse(str,len);
    
    cout<<"Reversed String of is= ";
    for(int i=0;i<len;i++){
        cout<<str[i]<<" ";
    }   
    return 0;
}

Stack_string:: Stack_string(int size):str{nullptr},n{0},top{-1}{
	cout<<"Stack is created with size= "<<size<<endl;
	n=size;
    str=new char[size];
}

void Stack_string:: push(char ch){
	 top++;//incrementing to the current index
     if(top==n){
        cerr<<"Stack Overflow"<<endl;
        return;
    }
    str[top]=ch;
    return;
}

void Stack_string:: pop(){
    if(top==-1){
        cerr<<"Stack Underflow"<<endl;
        return;
    }
    char *elemToDel=str+top;
    cout<<*elemToDel<<" Is deleted "<<endl;
    delete elemToDel;
    top--;
}

bool Stack_string::empty() const{
    if(top==-1)
        return true;
    else 
        return false;
}
int Stack_string::size() const{
    return top+1;//no. of curr elements
}

char Stack_string::peek() const{
    if(top!=-1)
		return str[top];
	else {
        cout<<"No elems are present in the Stack"<<endl;
        return CHAR_MIN;
    }
		
}

Stack_string::~Stack_string(){
    cout<<"Stack is now deleted"<<endl;
    top=-1;
    delete [] str;
}

