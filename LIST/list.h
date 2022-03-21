#include <iostream>
using namespace std;

template<typename key, typename info>
class sequence
{
    struct node
    {
        key k;
        info i;
        node *next;
    }
    node *head;
    node *tail;
    public:
    sequence();
    ~sequence();
    sequence(const sequence<key,Info>);
    Info getElement(Const key&);
    bool insertAfter(const key& k,const info& i,const key& where,int occurance=1);
    bool insertBefore(const Key& k,const info& i,const key& where,int occurance=1);
//insert elements in the middle of list
    void insertFront(const key&,const info&);
    void insertBack(const key&,const info&);
//insert elements in the front/back of the linked list
    bool delete(const key& which,int occurance=1);
    bool search(const key& what, int occurance=1);
    
    sequence<key,info>& operator=(const sequence<key, info>&);
    sequence<key,info>& operator+(const sequence<key, info>&) const;
    sequence<key,info>& operator+=(const sequence<key, info>&) const;
//operators implement
    void print();
    bool swap(const key& key1,const key& key2,int accurance=1);
};

template<typename key,typename info>
bool sequence<key,info>::insertAfter(const key& k,const info& i,const key& where,
int occurance=1){
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

