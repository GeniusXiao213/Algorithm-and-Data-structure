#include<stdio.h>
#include <iostream>
using namespace std;



template<typename Key,typename Info>
class doublyLinkedList
{
    struct node
    {
        Key key;
        Info info;
        node *next;
        node *back;
        public:
        node(const Key&k,const Info& i);
    };
    node *head;
    node *rear;
    public:
    class iterator
    {
        node *current;
    public:
        iterator(){current=nullptr};
        iterator& operator++();
        iterator& operator--(int num);
        iterator& operator--();
        iterator& operator--(int num);
    }
    const doublyLinkedList& operator=(const doublyLinkedList& l1);
    doublyLinkedList();
    ~doublyLinkedList();
    bool getInfo(const Info& data) const;
    bool getKey(const Key& data) const;
    void insertFirst(const Key&k, const Info&i);
    void insertLast(const Key&k, const Info&i);
    void insert(const Key&k,const Info&i,const Key&where);
    bool deleteNode(const Key&which);
    
};

template<typename Key,typename Info>
void doublyLinkedList<Key,Info>::insertFirst(const Key&k, const Info&i)
{
    node *newNode=new node;
    newNode->key=k;
    newNode->info=i;
    if(head==nullptr)
    {
        head=rear=newNode;
    }
    else
    {
    newNode->next=head;
    newNode->back=nullptr;
    head->back=newNode;
    head=newNode;
    }
}

template<typename Key,typename Info>
void doublyLinkedList<Key,Info>::insertLast(const Key&k, const Info&i)
{
    node *newNode=new node;
    newNode->key=k;
    newNode->info=i;
    if(head==nullptr)
    {
        head=rear=newNode;
    }
    else
    {
        rear->next=newNode;
        newNode->back=rear;
        newNode->next=nullptr;
        rear=newNode;
    }
}
 
template<typename Key,typename Info>
bool doublyLinkedList<Key,Info>::deleteNode(const Key&which)
{
    node *current=head;
    if(head==nullptr)
    {
        return false;
    }
    if(head->key==which)
    {
        node *temp=head;
        head=head->next;
        delete temp;
    }
    if(rear->key==which)
    {
        node *temp=rear;
        rear=rear->back;
        delete rear;
    }
    while(current)
    {
        if(current->key==which)
        {
        current->back->next=current->next;
        current->next->back=current->back;
        delete current;
        return true;
        }
        current=current->next;
    }
    return false;
    
}

template<typename Key,typename Info>
void doublyLinkedList<Key,Info>::insert(const Key&k,const Info&i,const Key&where)  //insertbefore
{
    node *newNode=new node(k,i);
    node *current=head->next;
    if(head==nullptr)
    {
        head=rear=newNode;
    }
    if(head->key==where)
    {
        newNode->next=head;
        newNode->back=nullptr;
        head->back=newNode;
        head=newNode;
    }
    if(rear->key==where)
    {
        rear->back->next=newNode;
        newNode->back=rear->back->next;;
        newNode->next=rear;
        rear->back=newNode;
    }
    while(current)
    {
        if(current->key==k)
        {
            current->back->next=newNode;
            newNode->back=current->back;
            newNode->next=current;
            current->back=newNode;
        }
        current=current->next;
    }
}
