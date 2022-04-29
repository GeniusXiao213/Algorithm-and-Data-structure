#include<stdio.h>
#include <iostream>
using namespace std;

//a stack is a list of homogenous elements in which the addition and deletion of elements occurs only at one end, called the top of the stack
//last in first out
class stack
{
    int maxSize;
    int top;
    int *list;
    void copyStack(const stack& otherstack);
public:
    stack();
    ~stack();
    stack(const stack& otherstack);
    bool isEmpty() const;
    bool isFull() const;
    void push(const int element);
    void pop();
    int returnTop() const;
};

void stack::pop()
{
    if(!isEmpty())
    {
        top--;
    }
    else{
        cout<<"can not remove an element from an empty list!"<<endl;
    }
}

stack::stack()
{
    top=0;
}
stack::~stack()
{
    delete[] list;
}

int stack::returnTop() const{
    return list[top-1];
}

void stack::push(const int element)
{
    if(!isFull())
    {
        list[top]=element;
        top++;
    }
    else{
        cout<<"stack is full!can not add a new element!"<<endl;
    }
}

stack::stack(const stack& otherstack)
{

}

bool stack::isEmpty() const{
    return (top==0);
}

bool stack::isFull() const{
    return (top==maxSize);
}

