#include<stdio.h>
#include <iostream>
using namespace std;

//class
template<class Type>

class linkedListType
{
    struct node
    {
        int info;
        node *next;
    };
    node *head;
    node *tail;
private:
    void reversePrint(nodeType<Type> *current) const;
};

template<class Type>
void linkedListType<Type>::reversePrint(nodeType<Type> *current) const
{
    if(current!=null)
    {
        reverse(current->next);
        cout<<current->info<<endl;
    }

}