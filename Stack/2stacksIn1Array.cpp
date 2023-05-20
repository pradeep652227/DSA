#include <iostream>
#include <climits>

using namespace std;

class TwoStacks
{   
    int *arr;
    int n;
    int top1;
    int top2;
 public:   
    TwoStacks(int size);
    void push1(int d);
    void push2(int d);
    void pop1();
    void pop2();
    bool empty1() const;
    bool empty2() const;
    int size1() const;
    int size2() const;
    int peek1() const;
    int peek2() const;

    ~TwoStacks();
};
int main(){
    TwoStacks s2(5);
    s2.push1(1);
    s2.push2(5);
    s2.push1(2);
    s2.push1(3);

    cout<<"Top1= "<<s2.peek1()<<" Top2= "<<s2.peek2()<<endl;
    return 0;
}

TwoStacks:: TwoStacks(int size):arr{nullptr},n{size},top1{-1},top2{size}{
    arr=new int[n];
}

void TwoStacks:: push2(int d){
    if(top2-top1==1){
        cout<<"Stack Overfloow for 2nd Stack (top2)"<<endl;
        return;
    }
    top2--;
    arr[top2]=d;
    return;
}

void TwoStacks::push1(int d){
     if(top2-top1==1){
        cout<<"Stack Overfloow for 1st Stack (top1)"<<endl;
        return;
    }
    top1++;
    arr[top1]=d;
    return;
}

void TwoStacks:: pop2(){
    if(top2==n){
        cout<<"Stack Underflow for 2nd Stack (top2)"<<endl;
        return;
    }
    int *elemToDel=arr+top2;
    cout<<*elemToDel<<" is Deleted from 2nd Stack"<<endl;
    delete elemToDel;
    top2++;
    return;
}
void TwoStacks:: pop1(){
    if(top1==-1){
        cout<<"Stack Underflow for 1st Stack (top1)"<<endl;
        return;
    }
    int *elemToDel=arr+top1;
    cout<<*elemToDel<<" is Deleted from 1st Stack"<<endl;
    delete elemToDel;
    top1--;
    return;
}

bool TwoStacks::empty1() const{
    if(top2==n)
        return true;
    else 
        return false;
}
bool TwoStacks::empty2() const{
    if(top1==-1)
        return true;
    else 
        return false;
}

int TwoStacks::size1() const{
    return top1+1;
}
int TwoStacks::size2() const{
    return (n-top2);
}

int TwoStacks::peek2() const{
    if(top2==n){
        cout<<"No Element in 2nd Stack"<<endl;
        return INT_MAX;
    }
    return arr[top2];
}
int TwoStacks::peek1() const{
    if(top1==-1){
        cout<<"No Element in the 1st Stack"<<endl;
        return INT_MIN;
    }
    return arr[top1];
}

TwoStacks:: ~TwoStacks(){
    int n=0;
    delete [] arr;
}
