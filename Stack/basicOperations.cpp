#include <iostream>
#include "stack.cpp"
using namespace std;

int main()
{   
    Stack s(5);
    s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);
	
	cout<<s.size()<<endl<<endl;
	
	cout<<"Top is at "<<s.peek()<<endl;
	s.pop();
	cout<<"Top is at "<<s.peek()<<endl;
	s.pop();
	cout<<"Top is at "<<s.peek()<<endl;
	s.pop();
	cout<<"Top is at "<<s.peek()<<endl;
	s.pop();
	cout<<"Top is at "<<s.peek()<<endl;
	cout<<"Is stack empty? "<<s.empty()<<endl;
	cout<<endl;
	s.pop();
	cout<<"Is stack empty? "<<s.empty()<<endl;

	
    return 0;
}