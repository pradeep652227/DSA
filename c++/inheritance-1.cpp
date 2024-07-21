#include <bits/stdc++.h>

using namespace std;

class Base
{
    int x;

public:
    Base() : x{0} { cout << "Base Default Constructor" << endl; }
    Base(int val) : x{val} { cout << "Base Overloaded Constructor" << endl; }
    int getVal() const { return x; }
    virtual void test(int x=0) { cout << "Base Test" << endl; }
    Base &operator=(const Base &rhs)
    {
        if (this != &rhs)
        {
            x = (rhs.x) + 5;
        }
        return *this;
    }
    ~Base() { cout << "Base Destructor" << endl; }
};

class Derived : public Base
{
    int y;

public:
    using Base::Base;
    Derived(int val = 0) : Base{val * 2}, y{val} { cout << "Derived Overloaded Constructor" << endl; }
    // void test() { cout << "Derived Test" << endl; }
    void child(){cout<<"Child"<<endl;}
    Derived &operator=(const Derived &rhs)
    {
        if (this != &rhs)
        {
            y = rhs.y;
            Base::operator=(rhs);
        }

        return *this;
    }
    ~Derived() { cout << "Derived Destructor" << endl; }
};

int main()
{
    Derived d(200);
    Base b(10);
    Base *d1 = new Derived();
    d1->test(5);
    cout << b.getVal() << endl;
    return 0;
}