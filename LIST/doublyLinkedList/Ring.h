#include<stdio.h>
#include <iostream>
using namespace std;

template<typename Key,typename Info>
class Ring
{
//doubly linked ring 
//iterator(++,--,implementation)//poistion is pointed by interators
private:
    class node
    {
        Key key;
        Info info;
        node *next;
        node *prev;  //doubly linked list has two nodes point to the previous and afterwards node respectively
    public:
        node(const Key& k,const Info& i);
        node(const Key& k,const Info& i,node *nex,node *pr)
        {
            key=k;
            info=i;
            prev=pr;
            next=nex;
        }
        void print()
        {
            cout << "<"<<this->key << "," << this->info<<"> ";
        }
    };
    
public:
    class iterator
    {
        node *itr;  //pointer to a node type
        friend class Ring;
        friend class node;
        
    //no tail since it's a ring structure
    public:
    iterator()
    {
        itr=nullptr;
    }
    //there is no need to write a deconstructor for this class only consists a pointer
    iterator(const iterator& otherIterator);
    iterator(node* nodeItr){itr=nodeItr;}
    iterator inext()
    {
        if(itr!=nullptr) itr=itr->next;
        return *this;
    }
    iterator iprev()
    {
        if(itr!=nullptr) itr=itr->prev;
        return *this;
    }
    iterator& operator++(){itr=itr->next;return *this;}
    iterator& operator++(const int num)
    {
        for(int i=0;i<num;i++)
        {
            itr=itr->next;
        }
        return *this;
    }  //increment the iterator by number bigger than 1
    iterator& operator--(){itr=itr->prev;return *this;}
    iterator& operator--(const int num){
        for(int i=0;i<num;i++)
        {
            itr=itr->prev;
        }
        return *this;
    }
    //iterator& operator+=(const iterator& other);
    bool operator!=(const iterator& other) const
    {
        return itr!=other.itr;
    }
    bool operator==(const iterator& other) const
    {
        return itr==other.itr;
    }
    // const Key& operator*() const { return itr->key; }
    // const Info& operator*() const { return itr->info; }
    node* operator*() const
    {
        return this->itr;
    }
    };
    Ring();
    ~Ring();
    //Ring(const Ring<Key,Info>& other);
    //void insertAfter(const Key&k,const Info&i,const iterator& ite);
    //void addBack(const Key&k,const Info&i)
    //{
    //    
    //}
    //bool remove(const iterator& ite);
    bool isEmpty() const{return (size==0);}
    iterator begin() const{return iterator(head);}
    iterator end() const{return iterator(head->prev);}
    void print()
    {
        if(isEmpty())
        {
            cout<<"It is a empty ring!"<<endl;
        }
        else
        {
        iterator current=begin();
        current.itr->print();
        while(current!=begin())
        {
            current.itr->print();
            ++current;
        }
        }
        
    }
private:
    node* head;
    size_t size;

};


// template<typename Key,typename Info>
// void Ring<Key,Info>::insertAfter(const Key&k,const Info&i,const iterator& ite)
// {
//     iterator current=begin();
//     node* newNode=new node(k,i);
//     if(isEmpty())
//     {
//         head=newNode;
//         newNode->next=head;
//         newNode->prev=head;
//         size++;
//     }
//     else if(size==1)
//     {
//         head->next=newNode;
//         newNode->prev=head;
//         newNode->next=head;
//         head->prev=newNode;
//         size++;
//     }
//     else
//     {
//         while(current!=ite)
//         {
//             ++current;
//         }
//         current.next.prev=newNode;
//         newNode.next=current.next;
//         current.next=newNode;
//         newNode.back=current;
//         size++;
//     }

// }

template<typename Key,typename Info>
Ring<Key,Info>::iterator::iterator(const iterator& otherIterator)
{
    itr=otherIterator.itr;
}

template<typename Key,typename Info>
Ring<Key,Info>::node::node(const Key&k,const Info& i)
{
    key=k;
    info=i;
    prev=nullptr;
    next=nullptr;
}
template<typename Key,typename Info>
Ring<Key,Info>::Ring()
{
    head=nullptr;
    size=0;
}

template<typename Key,typename Info>
Ring<Key,Info>::~Ring()
{
    iterator current=begin();
    while(current!=end())
    {
        delete current.itr;
        ++current;
    }
    delete end().itr;
    size=0;
}
template<typename Key,typename Info>
void split(const Ring<Key,Info> &source,Ring<Key,Info> &result1,int seq1,int repeat1,Ring<Key,Info> &result2,
int seq2,int repeat2)
{
    
} 