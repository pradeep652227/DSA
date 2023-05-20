#pragma once

class Stack
{   
    int *arr;
    int n;
    int top;
 public:   
    Stack(int size);
    void push(int d);
    void pop();
    bool empty() const;
    int size() const;
    int peek() const;

    ~Stack();
};