#include <iostream>
using namespace std;

template<typename key, typename info>
class sequence
{
    struct nodef
    {
        key k;
        info i;
        node *next;
    };
    node *head;
    node *tail;
    public:
    sequence();
    ~sequence();
    void destroyList();
//function to implement deconstuctor
    void copyList(const sequence<key,info>& otherList);
    sequence(const sequence<key,info>&);
    info getElement(const key& k,int occurance=1);
    bool insertAfter(const key& k,const info& i,const key& where,int occurance=1);
    bool insertBefore(const key& k,const info& i,const key& where,int occurance=1);
//insert elements in the middle of list
    void insertFront(const key&,const info&);
    void insertBack(const key&,const info&);
//insert elements in the front/back of the linked list
    bool remove(const key& which,int occurance=1);
    bool search(const key& what, int occurance=1);
    
    sequence<key,info>& operator=(const sequence<key, info>&);
    sequence<key,info>& operator+(const sequence<key, info>&) const;
    sequence<key,info>& operator+=(const sequence<key, info>&) const;
//operators implement
    void print();
    bool swap(sequence<key,info>& otherList);

    const sequence<key,info> shuffle(const sequence<key,info> &s1,int len1,const sequence<key,info> &s2,int len2,int repeat);
    
};


template<typename key,typename info>
const sequence<key,info> shuffle(const sequence<key,info> &s1,int len1,const sequence<key,info> &s2,int len2,int repeat)
{

}

template<typename key,typename info>
sequence<key,info>::sequence()
{
    head=nullptr;
    tail=nullptr;
}

template<typename key,typename info>
void sequence<key,info>::destoryList()
{
    node* current;
    current=head;
    while(head!=null)
    {
        delete current;
        current=current->next;
    }
    last=nullptr;
}

template<typename key,typename info>
sequence<key,info>::copyList(const sequence<key,info>& otherList)
{
    node *current; //pointer to traverse the list
    node *newNode; //pointer to create a node
    if(this.head!=nullptr)
    {
        destroy(this);
    }
    if(otherList.head==nullptr)
    {
        this.head=nullptr;
        this.tail=nullptr;
    }
    else
    {
        current=otherList.head;
        this.head=otherList.head;
        this.head->info=otherList.head->info;
        this.head->key=otherList.head->key;
        this.head->next=nullptr;
        this.tail=this.head;
        current=current->next;
        while(current!=nullptr)
        {
            newNode=new node;
            newNode->info=otherlist->info;
            newNode->key=otherList->key;
            newNode->next=nullptr;
            this.last->next=newNode;
            current=current->next;
        }
    }
}
template<typename key,typename info>
sequence<key,info>::sequence(const sequence<key,info>& otherList)
{
    copyList(otherList);
}

template<typename key,typename info>
sequence<key,info>::~sequence()
{
    destroyList();
}

template<typename key,typename info>
info getElement(const key& k,int occurance=1)
{
    node *current=head;
    while(current!=null)
    {
        if(curent->key==k)
        {
            return current->info;
        }
        current=current->next;
    }
    return 0;//can not find the element
    
}
template<typename key,typename info>
bool sequence<key,info>::insertAfter(const key& k,const info& i,const key& where,int occurance=1){
        node *current;
        node *newNode;
        newNode= new node;
        newNode->info=i;
        newNode->key=k;
        current=head;
        int occ=0;
        while(current!=nullptr)
        {
            if(current->key=where)
            {
                occ++;
            }

        }
        return false;
}

template<typename key,typename info>
bool sequence<key,info>::insertBefore(const key& k,const info& i,const key& where,int occurance=1)
{
    
}

template<typename key,typename info>
bool sequence<key,info>::remove(const key& which,int occurance=1)
{
    node *before; //a node just before the current node
    node *current;
    int count=0; 
    before=head;
    current=head->next;
    if(head->key==which)   //when the first note is the one we are looking for
    {
        delete head;
        return true;
    }
    while(current!=nullptr&&!count)
    {
        if(current->key==which)
        {
            before->next=current->next;
            count++;       //since occurance==1, this count variable is unnecessary
            if(tail==current)
            {
                tail=before;
            }
            delete current;
            return true;   
        }
        current=current->next;
        before=before->next;
    }
    return false;
}

template<typename key,typename info>
bool sequence<key,info>::search(const key& what,int occurance=1)
{
    node *current;
    current=head;
    while(current!=nullptr)
    {
        if(current->key==what)
        {
            return true;
        }
        current=current->next;
    }
    return false;
}

template<typename key,typename info>
bool sequence<key,info>::swap(const sequence<key,info>& otherList)
{
    sequence<key,info> temp;
    temp.copyList(otherList);
    otherList.copyList(this);
}

