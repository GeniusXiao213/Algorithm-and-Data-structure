#include<stdio.h>
#include <iostream>
using namespace std;

template<class T>
class linkedStack
{
private:
    struct node
    {
        T info;
        node *next;
    }
    node* top;

public:
    linkedStack(/* args */);
    ~linkedStack();
};

{
}

linkedStack::~linkedStack()
{
}

